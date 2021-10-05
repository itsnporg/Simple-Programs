require_relative './clear_screen'
require_relative './Todo'

class Session
  def initialize(username, db)
    @username = username
    @db = db
  end

  def text_flasher(text)
    print "\e[5m#{text}\e[0m"
  end

  def run
    clear_screen
    # Get option from user
    # continue option loop _unless exit option is pressed
    option = 0
    until option == 4
      # ask for option _until valid option pressed
      loop do
        begin
          display_options
          text_flasher "\n>>  "
          option = gets.chomp
          break if option == 'a' || option == 'b' || option.to_i >= 1 && option.to_i <= 6

          puts 'Please enter an option between 1 and 6'.red
          gets
        rescue StandardError
          puts 'Please enter a valid option'.red
        end
        clear_screen
      end
      clear_screen
      log_out = run_option(option)
      return if log_out == 'log_out'

      clear_screen
    end
  end

  def display_title(message)
    puts message if message != ''
    puts '-' * 69
    puts ''
  end

  def display_options
    print 'Hello,'
    puts " #{@username}".green
    display_title('')

    puts 'Press an option to get started'

    puts "1. Add a todo     \t 2. List incomplete Todos".blue
    puts "3. List all todos \t 4. Mark todo completed".blue
    puts "5. Delete todo    \t".blue
    puts ''
    puts "a. Change user password\t b. Log out".blue
  end

  def run_option(option)
    case option
    when '1'
      add_new_todo
    when '2'
      display_incomplete_todos
      puts 'Press any key to continue...'
      gets
    when '3'
      display_all_todos
      puts 'Press any key to continue...'
      gets
    when '4'
      mark_todo_completed!
    when '5'
      delete_todo!
    when 'a'
      # puts 'Dev is lazy, will add feature later'
      change_user_password
    when 'b'
      # error code
      puts 'Logging you out...'.red
      sleep 1.5
      'log_out'
    else
      puts 'Invalid option'.red
    end
  end

  def add_new_todo
    display_title 'Add new todo'
    print 'Enter todo name: '.blue
    title = gets.chomp
    puts "Enter description for #{title}:".blue
    body = gets.chomp
    todo = Todo.new(@username, title, body)
    todo.save!(@db)
    puts "\nSuccess!".green
    puts 'Press any key to continue...'
    gets
  end

  def display_todo_description(index, todo)
    puts "#{index + 1}.\t#{todo[0]}:"
    puts "\t#{todo[1]}"
    print "Status: #{Todo.get_status(todo[3])}\n\n\n"
  end

  def display_all_todos
    display_title 'All todos'
    todos = Todo.get_all_todos(@username, @db)
    todos.each_with_index { |todo, index| display_todo_description(index, todo) }
  end

  def display_incomplete_todos
    display_title 'Incomplete todos'
    todos = Todo.get_incomplete_todos(@username, @db)
    todos.each_with_index { |todo, index| display_todo_description(index, todo) }
  end

  def mark_todo_completed!
    data = display_incomplete_todos
    print 'Enter the number for the todo you want to mark completed: '
    option = gets.chomp.to_i
    Todo.mark_todo_completed!(@db, data[option - 1][0], data[option - 1][1], data[option - 1][2])
    sleep 1
    puts 'Congrats! The todo was marked complete!'.green
    puts 'Press any key to continue...'
    gets
  end

  def delete_todo!
    data = display_all_todos
    print 'Enter the number for the todo you want to delete: '.red
    option = gets.chomp.to_i
    # puts data[option - 1][1]
    Todo.delete!(@db, data[option - 1][0], data[option - 1][1])
    sleep 1
    puts 'Success, Todo was deleted!'.green
    puts 'Press any key to continue...'
    gets
  end

  def change_user_password
    puts 'Are you sure you want to change your current password?[y/N] '.red
    return unless gets.chomp == 'y'

    print 'Enter new password: '.green
    new_password = gets.chomp
    User.change_password(@db, @username, new_password)
    sleep 1.5
    puts "Success! Your password has been changed for username: '#{@username}'"
    puts 'Press any key to continue...'
    gets
  end
end
