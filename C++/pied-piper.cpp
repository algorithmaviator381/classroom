#include <iostream>
#include <fstream>
#include <zlib.h>

void compressFile(const char* sourcePath, const char* destinationPath) {
    std::ifstream sourceFile(sourcePath, std::ios::binary);
    std::ofstream destinationFile(destinationPath, std::ios::binary);

    z_stream stream;
    stream.zalloc = Z_NULL;
    stream.zfree = Z_NULL;
    stream.opaque = Z_NULL;
    stream.avail_in = 0;
    stream.next_in = Z_NULL;

    int ret = deflateInit(&stream, Z_BEST_COMPRESSION);
    if (ret != Z_OK) {
        std::cerr << "Failed to initialize compression" << std::endl;
        return;
    }

    char inBuffer[1024];
    char outBuffer[1024];

    do {
        sourceFile.read(inBuffer, sizeof(inBuffer));
        stream.avail_in = sourceFile.gcount();
        stream.next_in = reinterpret_cast<Bytef*>(inBuffer);

        do {
            stream.avail_out = sizeof(outBuffer);
            stream.next_out = reinterpret_cast<Bytef*>(outBuffer);
            ret = deflate(&stream, Z_FINISH);
            if (ret == Z_STREAM_ERROR) {
                std::cerr << "Compression error" << std::endl;
                deflateEnd(&stream);
                return;
            }
            destinationFile.write(outBuffer, sizeof(outBuffer) - stream.avail_out);
        } while (stream.avail_out == 0);
    } while (sourceFile);

    deflateEnd(&stream);
    sourceFile.close();
    destinationFile.close();
}

void decompressFile(const char* sourcePath, const char* destinationPath) {
    std::ifstream sourceFile(sourcePath, std::ios::binary);
    std::ofstream destinationFile(destinationPath, std::ios::binary);

    z_stream stream;
    stream.zalloc = Z_NULL;
    stream.zfree = Z_NULL;
    stream.opaque = Z_NULL;
    stream.avail_in = 0;
    stream.next_in = Z_NULL;

    int ret = inflateInit(&stream);
    if (ret != Z_OK) {
        std::cerr << "Failed to initialize decompression" << std::endl;
        return;
    }

    char inBuffer[1024];
    char outBuffer[1024];

    do {
        sourceFile.read(inBuffer, sizeof(inBuffer));
        stream.avail_in = sourceFile.gcount();
        stream.next_in = reinterpret_cast<Bytef*>(inBuffer);

        do {
            stream.avail_out = sizeof(outBuffer);
            stream.next_out = reinterpret_cast<Bytef*>(outBuffer);
            ret = inflate(&stream, Z_NO_FLUSH);
            if (ret == Z_STREAM_ERROR) {
                std::cerr << "Decompression error" << std::endl;
                inflateEnd(&stream);
                return;
            }
            destinationFile.write(outBuffer, sizeof(outBuffer) - stream.avail_out);
        } while (stream.avail_out == 0);
    } while (sourceFile);

    inflateEnd(&stream);
    sourceFile.close();
    destinationFile.close();
}

int main() {
    const char* inputFile = "input.pdf";
    const char* compressedFile = "compressed.pdf";
    const char* decompressedFile = "decompressed.pdf";

    // Compress the PDF file
    compressFile(inputFile, compressedFile);
    std::cout << "File compressed." << std::endl;

    // Decompress the compressed PDF file
    decompressFile(compressedFile, decompressedFile);
    std::cout << "File decompressed." << std::endl;

    return 0;
}
