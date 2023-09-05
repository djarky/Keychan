import os
import re

def process_file(file_path):
    with open(file_path, 'r') as f:
        content = f.read()

    # Busca definiciones de funciones sin parámetros y reemplaza por "(void)"
    pattern = r'\b([a-zA-Z_][a-zA-Z0-9_]*)\(\)\s*{'
    content = re.sub(pattern, r'\1(void) {', content)

    with open(file_path, 'w') as f:
        f.write(content)

def process_directory(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(('.c', '.h')):
                file_path = os.path.join(root, file)
                process_file(file_path)

if __name__ == '__main__':
    target_directory = '/ruta/a/tu/directorio'  # Cambia esto a la ubicación de tus archivos
    process_directory(target_directory)
