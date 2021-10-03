require 'spec_helper'
require_relative '../Database'

describe Database do
    SPEC_DB_NAME = Time.now.to_s + '.db'
    db = nil

    it "creates new db" do
        db = Database.create_todo_db(SPEC_DB_NAME)
        expect(db).to be_truthy 
    end
    it "creates SQLite3 Database" do
        expect(db).to be_instance_of SQLite3::Database
    end
    it "creates users table" do
        message = db.execute 'SELECT * FROM users'
        expect(message).to be_truthy 
    end
    it "creates dummy account" do
        message = db.execute 'SELECT * FROM users WHERE username="admin"'
        expect(message).not_to eql []
    end
end
