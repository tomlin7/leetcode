dir = "DLRU"  # Directions
#     D  R
dr = [1, 0]
dc = [0, 1]


# n because square matrix
def is_valid(row: int, col: int, n: int, maze: list):
    return 0 <= row < n and 0 <= col < n and maze[row][col] == 1


def find_path(row: int, col: int, n: int, maze: list, ans: list, current_path):
    if row == n - 1 and col == n - 1:
        # finished
        ans.append(current_path)
        return

    maze[row][col] = 0  # Mark as visited
    for i in range(2):
        next_row = row + dr[i]
        next_col = col + dc[i]

        if is_valid(next_row, next_col, n, maze):
            current_path += dir[i]
            find_path(next_row, next_col, n, maze, ans, current_path)
            current_path = current_path[:-1]  # Backtrack

    maze[row][col] = 1  # Mark as unvisited


maze = [[1, 0, 0, 0], [1, 1, 0, 1], [0, 1, 0, 0], [1, 1, 1, 1]]
result = []
n = len(maze)
current_path = ""

if maze[0][0] != 0 and maze[n - 1][n - 1] != 0:
    find_path(0, 0, n, maze, result, current_path)


print(result)
