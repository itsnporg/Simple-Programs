require("last")

# A linked list
class List
  # Nodes for the linked list.
  class Node
    # Get the last facility which scans to the end of the list.
    include Follower

    def initialize(d, n = nil)
      @val = d
      @next = n
    end
    attr_reader :next, :val
    attr_writer :next
  end

  # Get the printing facility.
  include Printer

  # Create the list with its first node.
  def initialize(first)
    @head = Node.new(first)
  end

  # Add at the front.  We can only add, and the list is created with one
  # node, so no special case for empty list.  How nice.
  def at_front(v)
    n = Node.new(v)
    n.next = @head
    @head = n
  end

  # Add to the end of the list.
  def at_end(v)
    n = Node.new(v)
    @head.last.next = n
  end

  # Process each member of the list.  The yield operator calls the block
  # sent to the function.
  def each
    p = @head
    while p != nil
      yield p.val
      p = p.next
    end
  end
end
See:Programming
