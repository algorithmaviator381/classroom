import cv2
import os


def resize_images(input_folder, output_folder, target_ratio):
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for filename in os.listdir(input_folder):
        if filename.endswith(('.png', '.jpg', '.jpeg')):
            input_path = os.path.join(input_folder, filename)
            output_path = os.path.join(output_folder, filename)

            img = cv2.imread(input_path)

            new_height = int(img.shape[1] / target_ratio)

            resized_img = cv2.resize(img, (img.shape[1], new_height))

            cv2.imwrite(output_path, resized_img)


if __name__ == "__main__":
    input_folder = r"C:\Users\pradi\OneDrive\Documents\classroom\ml\opencv\data"
    output_folder = r"C:\Users\pradi\OneDrive\Documents\classroom\ml\opencv\image"

    resize_images(input_folder, output_folder, 0.7092198581560284)
