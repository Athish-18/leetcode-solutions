import os

folder = "Leetcode-solutions"
readme_path = os.path.join(folder, "README.md")
levels = ["easy", "medium", "hard"]

table_header = """# LeetCode Solutions in C++

| #    | Title                                | Difficulty | Solution Link |
|------|--------------------------------------|------------|----------------|
"""

entries = []

for level in levels:
    dir_path = os.path.join(folder, level)
    if not os.path.exists(dir_path):
        continue

    for file in os.listdir(dir_path):
        if file.endswith(".cpp"):
            parts = file.split("-", 1)
            if len(parts) < 2:
                continue
            number = parts[0]
            title = parts[1].replace(".cpp", "").replace("-", " ").capitalize()
            link = f"{level}/{file}"
            entries.append((int(number), number, title, level.capitalize(), link))

entries.sort()

with open(readme_path, "w") as f:
    f.write(table_header)
    for _, number, title, difficulty, link in entries:
        f.write(f"| {number} | {title} | {difficulty} | [{link}]({link}) |\n")

print("README.md updated successfully.")
