class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        rows = defaultdict(set)
        cols = defaultdict(set)
        squares = defaultdict(set)
        # key = row/3, col/3


        for i in range(len(board)):
            for j, num in enumerate(board[i]):
                if num == ".":
                    continue
                if num in rows[i] or num in cols[j] or num in squares[(i // 3, j // 3)]:
                    return False
                rows[i].add(num)
                cols[j].add(num)
                squares[(i // 3, j // 3)].add(num)
        
        return True

        