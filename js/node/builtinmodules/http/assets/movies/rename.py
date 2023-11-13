import os


directory_path = os.getcwd()
jpg_files = [f for f in os.listdir(directory_path) if f.endswith('.jpg')]
jpg_files.sort()
counter = 1

for old_name in jpg_files:
    extension = os.path.splitext(old_name)[1]
    new_name = f'img{counter}{extension}'
    old_path = os.path.join(directory_path, old_name)
    new_path = os.path.join(directory_path, new_name)

    os.rename(old_path, new_path)
    counter += 1

print("All .jpg files have been renamed.")

# I wrote this python script to rename all the image files (for the movies page) in order


# Currently I am working on a project 
# My objective is to scan all images from a directory which has screenshots from 
# various movies and I want to rename each screenshot from the movie it belongs to.
