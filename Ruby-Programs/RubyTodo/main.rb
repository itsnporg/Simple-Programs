# frozen_string_literal: true

require 'sqlite3'

require_relative './App'

def main(db_name)
  app = App.new(db_name)
  app.run
end

DBNAME = 'test.db'
main(DBNAME)
