# frozen_string_literal: true

require 'colorize'

require_relative './clear_screen'
require_relative './Database'
require_relative './User'
require_relative './Todo'
require_relative './Session'

class App
  def initialize(db_name)
    @db = Database.get_db(db_name)
  end

  def text_flasher(text)
    print "\e[5m#{text}\e[0m"
  end

  def display_intro
    clear_screen

    puts 'Welcome to Ruby TODO'.green

    puts ''
    puts 'We\'re here to get stuff done!'

    puts '-' * 69
    puts ''
    sleep 1
  end

  def run
    # initial pause
    clear_screen
    sleep 0.75
    # Get option from user
    # continue option loop _unless exit option is pressed
    option = 0
    until option == 4
      # ask for option _until valid option pressed
      loop do
        display_intro
        display_options
        text_flasher "\n>>  "
        option = gets.chomp.to_i
        break if option >= 1 && option <= 4

        puts 'Please enter an option between 1 and 4'.red
        gets
        clear_screen
      rescue
        puts 'That is not a valid option, please try again!'.red
        gets
        clear_screen
      end
      clear_screen
      run_option(option)
      clear_screen
    end
  end

  def display_options
    puts ''
    puts 'Press an option to get started'
    puts "1. Login\t 2. Register".blue
    puts "3. Help \t 4. Exit".blue
  end

  def run_option(option)
    case option
    when 1
      user = authenticate_user
      if user
        session = Session.new(user, @db)
        session.run
      end

    when 2
      user = register_user!
      User.display_users(@db)
    when 3
      display_help
    when 4
      puts '"Bye byeee!" - Bijaya Shahi, 2020'
      sleep 2
      clear_screen
      exit 0
    else
      puts 'Invalid option'
    end
  end

  def authenticate_user
    puts '-' * 69
    print 'Enter your username: '.blue
    username = gets.chomp
    print 'Enter password: '.blue
    password = gets.chomp
    User.authenticate(username, password, @db)
  end

  def register_user!
    loop do
      clear_screen
      puts '-' * 69
      print 'Enter your username: '.blue
      username = gets.chomp
      print 'Enter password: '.blue
      password = gets.chomp
      print 'Enter password again: '.blue
      password2 = gets.chomp
      if password == password2
        break if User.register!(username, password, @db)
      else
        puts "Two passwords don't match".red
        gets
      end
    end
  end

  def display_help
    puts 'Ruby TODO'
    print 'Made by Rojan Rajbhandari '.green
    puts '(@rojanr)'
    puts '-' * 69
    puts ''
    puts = puts 'Help:'.blue
    puts 'लोरेम इप्सम लोरेम इप्सम. '.blue
    puts ''
    gets
  end
end
