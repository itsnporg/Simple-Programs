require 'base64'

require_relative './Database'

class User
  attr_reader :username

  def initialize(username, password)
    @username = username
    @password = password
  end

  def to_s
    @username
  end

  def self.authenticate(username, password, db)
    data = db.execute "SELECT * FROM users WHERE username='#{username}'"

    # check _if user exist
    if data.empty?
      puts 'Error: No such user found.'.red
      puts 'Perhaps try registering first?'
      gets
      false
    else
      if Base64.encode64(password) == data[0][1]
        puts 'Authenticated!'.green
        gets
        # return username
        data.first.first
      else
        puts "Error: Wrong password #{username}, try again".red
        gets
        false
      end
    end
  end

  def self.register!(username, password, db)
    data = db.execute "SELECT * FROM users WHERE username='#{username}'"
    if !data.empty?
      puts 'Sorry, a user by that username already exists'.red
      gets
    else
      puts 'Registering user...'
      sleep 0.25
      password_enc = Base64.encode64(password)
      db.execute 'INSERT INTO users VALUES ( ?, ? )', [username, password_enc]
      puts 'Registration successful!'.green
      puts "You may log in as '#{username}' now"
      gets
      return username
    end
  end

  def self.display_users(db)
    data = db.execute 'SELECT * from users'
    p data
  end

  def self.change_password(db, username, new_password)
    db.execute "DELETE FROM users WHERE username='#{username}'"
    db.execute 'INSERT INTO users VALUES ( ?, ?)', [username, new_password]
  end
end
