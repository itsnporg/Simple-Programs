require 'base64'
require 'sqlite3'

class Database
  def self.get_db(db_name)
    # Get or create new database db_name
    if File.exist?(db_name)
      SQLite3::Database.open(db_name)
    else
      create_todo_db(db_name)
    end
  end

  def self.create_todo_db(db_name)
    db = SQLite3::Database.new(db_name)

    # Create users table
    db.execute <<-SQL
			CREATE TABLE users (
				username VARCHAR(30) NOT NULL UNIQUE,
				password VARCHAR(120) NOT NULL
			);
    SQL

    # add dummy admin account
    password_enc = Base64.encode64('password')
    db.execute 'INSERT INTO users VALUES ( ?, ? )', ['admin', password_enc]

    # Create todos table
    db.execute <<-SQL
			CREATE TABLE todos (
        user VARCHAR(30) NOT NULL,
				title VARCHAR(120) NOT NULL,
				body VARCHAR(120),
				completed NUMBER(1)
			);
    SQL
    db
  end
end
