import os

def print_directory_tree(path):
  """Prints a directory tree."""

  for root, directories, files in os.walk(path):
    level = root.replace(path, '').count(os.sep)
    indent = ' ' * 4 * level
    print('{}{}/'.format(indent, os.path.basename(root)))
    for directory in directories:
      print('{}{}'.format(indent, directory))
    for file in files:
      print('{}{}'.format(indent, file))

if __name__ == '__main__':
  path = input('Enter the path to the directory you want to print the tree for: ')
  print_directory_tree(path)

