import ctypes                                       # Low-Level Array from C

class DynamicArray:
    def __str__(self):
        uhm = ""
        for i in range(self._n):
            uhm += str(self._A[i]) + " "
        return uhm

    def __init__(self):
        """Create an empty array."""
        self._n = 0
        self._capacity = 1
        self._A = self._make_array(self._capacity)
    
    def __len__(self):
        """Returns number of elements stored in array"""   
        return self._n

    def __getitem__(self, k):
        """Returns element at index k"""
        if not 0 <= k < self._n:
            raise IndexError('invalid index')
        return self._A[k]
    
    def append(self, obj):
        """Add object to the end of array"""
        if self._n == self._capacity:
            self._resize(2*self._capacity)
        self._A[self._n] = obj
        self._n += 1
        
    def _resize(self, c):
        """Resize internal array to capacity c"""
        B = self._make_array(c)
        for k in range(self._n):
            B[k] = self._A[k]
        self._A = B
        self._capacity = c

    def _make_array(self, c):
        """Returns a new array with capacity c"""
        return (c * ctypes.py_object)()
        

