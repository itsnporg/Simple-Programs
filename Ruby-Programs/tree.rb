require("last")

class Tree
  class Node
    # Again, we include the follower class.
    include Follower

    def initialize(d)
      @val = d
      @lft, @rgt = nil
    end
    attr_reader :lft, :rgt, :val
    attr_writer :lft, :rgt

    def next
      return @rgt
    end

    def insert(new)
      if new.val < @val then
        if @lft == nil then
          @lft = new
        else
          @lft.insert(new)
        end
      else
        if @rgt == nil then
          @rgt = new
        else
          @rgt.insert(new)
        end
      end
    end


    def each(block)
      if @lft then @lft.each(block) end
      block.call(@val)
      if @rgt then @rgt.each(block) end
    end
  end

  include Printer

  def initialize(first)
    @root = Node.new(first)
  end

  def insert(v)
    @root.insert(Node.new(v))
  end

  def max
    return @root.last.val
  end


  def each(&blk)
    @root.each(blk)
  end
end
