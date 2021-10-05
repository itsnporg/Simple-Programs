class Todo
  def initialize(username, title, body)
    @username = username
    @title = title
    @body = body
    # use 0 & 1 instead of true and false because SQLite doesn't support bools
    @completed = 0
  end

  def delete_todo!(db, todo_title)
    db.execute "DELETE FROM todos WHERE title=#{todo_title}"
  end

  def save!(db)
    db.execute 'INSERT INTO todos VALUES (?, ?, ?, ?)', [@username, @title, @body, @completed]
  end

  def self.display_todos(db)
    data = db.execute 'SELECT * from todos'
    puts data
  end

  def self.get_all_todos(username, db)
    db.execute "SELECT * from todos WHERE user='#{username}'"
  end

  def self.get_incomplete_todos(username, db)
    db.execute "SELECT * from todos WHERE user='#{username}' AND completed=0"
  end

  def self.get_status(status_code)
    return 'Completed' if status_code == 1

    'Incomplete'
  end

  def self.mark_todo_completed!(db, user, title, body)
    db.execute "DELETE FROM todos WHERE user='#{user}' AND title='#{title}'"
    db.execute 'INSERT INTO todos VALUES ( ?, ?, ?, ?)', [user, title, body, 1]
  end

  def self.delete!(db, user, title)
    puts user
    puts title
    db.execute "DELETE FROM todos WHERE user='#{user}' AND title='#{title}'"
  end
end
