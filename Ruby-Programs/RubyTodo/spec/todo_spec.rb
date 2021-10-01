require_relative '../Todo'
require_relative '../Database'

describe Todo  do
  context "When testing Todo class" do
    it 'adds todo using session' do
      db = Database.get_db('test.db')
      todo = Todo.new('admin', 'test', 'asdf')
      todo.save!(db)
      expect(todo).to be_truthy
    end

    it 'makes sure 2 + 2 is 4' do
      a = 2
      b = 2
      expect(a + b).to eq 4
    end
  end
end
