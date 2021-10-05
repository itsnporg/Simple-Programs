require_relative "./clear_screen"

class Game
  def initialize(player_name, size)
    @board = []
    size.times { @board << ("_" * size).split("") }

    @player_name = player_name
    @is_game_won = false
    @PLAYERS = ["O", "X"]
    @active_player = @PLAYERS[0]
  end

  def play
    display_init

    # gameloop
    while !@is_game_won
      x, y = get_user_input(@active_player)
      add_mark(@active_player, x, y)
      display_board
      change_active_mark

      if check_win
        puts "Game over"
        # TODO: specify which player won
        break
      end
    end
  end

  def self.display_intro
    clear_screen
    puts "Welcome to Alu Cross [Plus]."
    print "-" * 32 + "\n"
  end

  def self.get_player_name
    print "What's your name, human? "
    gets.chomp.strip
  end

  def self.get_board_size
    print "And what would be the board size: "
    gets.chomp.to_i
  end

  def display_init
    clear_screen
    
    puts "\nBegin game!"
    size = @board.length

    size.times do |i|
      print "|"
      size.times { |j| print " X#{i + 1}#{j + 1} " }
      puts "|"
    end

    puts "Press 'q' to Quit, 'u' to Undo"
  end

  def display_board
    @board.each do |row|
      print "|"
      row.each { |elem| print " " + elem + " " }
      puts "|"
    end
  end

  def get_user_input(active_player)
    while true
      print("Enter X coord for #{active_player}: ")
      x = gets.chomp
      print("Enter Y coord for #{active_player}: ")
      y = gets.chomp

      # check if x and y can be converted into int
      begin
        x = x.to_i
        y = y.to_i

        # i f coordinates are valid return else continue inf loop
        if (x > 0 && y > 0 && x <= @board.length && y <= @board.length) && @board[x - 1][y - 1] == "_"
          clear_screen
          return x, y
        elsif @board[x - 1][y - 1] != "_"
          puts "\nThat coordinate has already been filled"
        else
          puts "\nEnter valid coordinates"
        end
      rescue => exception
        puts "\nEnter valid coordinates"
      end
    end
  end

  def add_mark(mark, x, y)
    @board[x - 1][y - 1] = mark
  end

  def change_active_mark
    # get index of current mark and shift by 1 place or recurse into start of arrya
    i = @PLAYERS.find_index(@active_player) + 1
    if i == @PLAYERS.length
      i = 0
    end
    @active_player = @PLAYERS[i]
  end

  def check_prim_diag_win
    size = @board.length
    win = true

    size.times do |i|
      if i < size - 1
        if @board[i][i] != @board[i + 1][i + 1] || @board[i][i] == "_"
          win = false
          break
        end
      end
    end
    win
  end

  def check_sec_diag_win
    size = @board.length
    win = true

    size.times do |i|
      if i < size - 1
        if @board[i][size - i - 1] != @board[i + 1][size - i - 2] || @board[i][size - i - 1] == "_"
          win = false
          break
        end
      end
    end
    win
  end

  def check_row_win(i, j)
    if j == 0
      true
    else
      if @board[i][j] == @board[i][j - 1] && @board[i][j] != "_"
        return check_row_win(i, j - 1)
      else
        return false
      end
    end
    true
  end

  def check_col_win(i, j)
    if i == 0
      true
    else
      if @board[i][j] == @board[i - 1][j] && @board[i][j] != "_"
        return check_col_win(i - 1, j)
      else
        return false
      end
    end
    true
  end

  def check_row_col_win
    size = @board.length

    size.times do |i|
      if check_row_win(i, size - 1) || check_col_win(size - 1, i)
        return true
      end
    end

    false
  end

  def check_win
    "" '
        Assume player is winning by default, if any row, column or diagonal doesn\'t match winning condition
        (same mark and not _) then break check loop
    ' ""
    check_prim_diag_win || check_sec_diag_win || check_row_col_win
  end
end
