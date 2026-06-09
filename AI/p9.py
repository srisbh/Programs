board=[" "]*9
player="X"
while " " in board:
    print(f"""
          {board[0]} |  {board[1]}  |  {board[2]}
          --------------
          {board[3]} |  {board[4]}  |  {board[5]}
          --------------
          {board[6]} |  {board[7]}  |  {board[8]}
          """)
    move=int(input(f"{player}'s turn (0-8): "))
    if board[move]==" ":
        board[move]=player
        if any(
            board[i]==board[j]==board[k]==player
            for i,j,k in [
                 (0,1,2),(3,4,5),(6,7,8),(0,3,6),(1,4,7),(2,5,8),(0,4,8),(2,4,6)
        ]):
            print(player,"wins!")
            break
        player="O" if player=="X" else "X"
    else:
        print("Invalid move!")
else:
    print("It's a tie")