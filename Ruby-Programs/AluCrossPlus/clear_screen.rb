def clear_screen
  begin
    puts `clear`
  rescue
    begin
      puts `cls`
    rescue
      # pass
    end
  end
end
