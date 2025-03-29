import os

folders = "common", "file", "meta", "net", "stl", "timing", "math", "crypto"

file_directories = [(directory.replace('\\', '/'), [f"/{file}" for file in files]) for folder in folders for directory, _, files in os.walk(folder)]
max_directory_length = max(map(len, (file_path[0] for file_path in file_directories)))
max_file_lengths = [max(map(len, file_paths)) for _, file_paths in file_directories]

LINE_WIDTH = 100
total_line_count = 0
total_char_count = 0
total_file_count = sum(map(len, (file_path for _, file_path in file_directories)))
for (directory, file_paths), max_file_length in zip(file_directories, max_file_lengths):
 directory_line_count = 0
 directory_char_count = 0
 directory_str = f"{directory} ({len(file_paths)})"
 print('-'*((LINE_WIDTH - len(directory_str)) // 2) + directory_str + '-'*((LINE_WIDTH - len(directory_str)) // 2 + (LINE_WIDTH - len(directory_str)) % 2))
 for file_path in file_paths:
  with open(f"{directory}{file_path}", "r") as file_handler:
   file_contents = file_handler.read()
   line_count = file_contents.count('\n')
   char_count = len(file_contents)
   directory_line_count += line_count
   directory_char_count += char_count
   print(f"{file_path.ljust(max_file_length)}: {line_count} lines, {char_count} chars")
 total_line_count += directory_line_count
 total_char_count += directory_char_count

print('\n'*5)
print('-'*50 + "Total" + '-'*50)
print(f"- Line Count: {total_line_count}")
print(f"- Char Count: {total_char_count}")
print(f"- File Count: {total_file_count}")