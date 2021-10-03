require_relative "./Game"

def main
  Game.display_intro
  player_name = Game.get_player_name
  board_size = Game.get_board_size

  game = Game.new(player_name, board_size)

  while true
    game.play
    print "Would you like to play again?[y/n] "
    play_again = gets.chomp.downcase
    while true
      if play_again == "y"
        break
      elsif play_again == "n"
        return
      end
    end
  end
end

main
