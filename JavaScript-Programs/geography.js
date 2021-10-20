/* Haversine formula & helper */
function rad(x) {
  return (x * Math.PI) / 180;
}

function getDistance(point1, point2) {
  // By knowing the radius of earth
  var R = 6378137;
  // And the difference in latitude between two coordinates
  var dLat = rad(point2.lat() - point1.lat());
  // as well as the difference in longitude between two coordinates
  var dLong = rad(point2.lng() - point1.lng());

  // We can use the haversine formula - see https://en.wikipedia.org/wiki/Haversine_formula
  var a =
    Math.sin(dLat / 2) * Math.sin(dLat / 2) +
    Math.cos(rad(point1.lat())) *
      Math.cos(rad(point2.lat())) *
      Math.sin(dLong / 2) *
      Math.sin(dLong / 2);

  var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
  var d = R * c;

  // To return the distance between two coordinates in meters.
  return d;
}

// Simple point implementation
class Point {
  constructor(lat, lng) {
    this.latitude = lat;
    this.longitude = lng;
  }

  lat() {
    return this.latitude;
  }

  lng() {
    return this.longitude;
  }
}

// So lets say we have
var pointA = new Point(58.24, 12.6);
var pointB = new Point(58.64, 14.12);

// We can retrieve the distance
var distance_in_meter = getDistance(pointA, pointB);

// And the output should result in around 99km according to google.
console.log(distance_in_meter);
