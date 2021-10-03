class Fractions:
  def __init__(self,n,d):
    self.x = n
    self.y = d

def numerator(P):
  return P.x

def denominator(P):
  return P.y

def fractionsSummation(P1, P2): 
  return Fractions(numerator(P1)*denominator(P2)+numerator(P2)*denominator(P1),denominator(P1)*denominator(P2))
def fractionsSubtraction(P1, P2):
  return Fractions(numerator(P1)*denominator(P2)-numerator(P2)*denominator(P1),denominator(P1)*denominator(P2))
def fractionsMultiply(P1, P2):
  return Fractions(numerator(P1)*numerator(P2),denominator(P1)*denominator(P2))
def fractionsDivider(P1, P2):
  return Fractions(numerator(P1)*denominator(P2),denominator(P1)*numerator(P2))
def RealP(P):
  return numerator(P)/denominator(P)


# isEqual
def isEqP(P1, P2):
  return numerator(P1)/denominator(P1) == numerator(P2)/denominator(P2)

# isLessThan
def isLtP(P1, P2):
  return numerator(P1)/denominator(P1) < numerator(P2)/denominator(P2)

# isGreaterThan
def isGtP(P1, P2):
  return numerator(P1)/denominator(P1) > numerator(P2)/denominator(P2)

# Application
print(RealP(fractionsSummation(Fractions(1,2),Fractions(3,4))))
print(RealP(fractionsSubtraction(Fractions(2,3),Fractions(3,6))))
print(RealP(fractionsMultiply(Fractions(2,4),Fractions(1,2))))
print(RealP(fractionsDivider(Fractions(2,7),Fractions(1,7))))
print(isEqP(Fractions(2,7),Fractions(1,7)))
print(isLtP(Fractions(4,8),Fractions(6,7)))
print(isGtP(Fractions(6,9),Fractions(2,7)))
print(RealP(fractionsSummation(Fractions(2,4),Fractions(1,2))))
