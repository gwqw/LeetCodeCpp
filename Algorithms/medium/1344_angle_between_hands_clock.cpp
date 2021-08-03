/**
    1344. Angle Between Hands of a Clock
Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

Example 1:
Input: hour = 12, minutes = 30
Output: 165

Example 2:
Input: hour = 3, minutes = 30
Output: 75

Example 3:
Input: hour = 3, minutes = 15
Output: 7.5

Example 4:
Input: hour = 4, minutes = 50
Output: 155

Example 5:
Input: hour = 12, minutes = 0
Output: 0

Constraints:
1 <= hour <= 12
0 <= minutes <= 59
Answers within 10^-5 of the actual value will be accepted as correct.

Algo:
30 -- 180
10 -- 60
5 -- 30
1h -- 30

ah = calcAngle(h, m)
	return h/12 * 360 % 360 + m/60 * 30
	
am = calcAngle(m):
	return m/60*360
	
calcAngleBetween(ah, am)
	if ah > am: swap(ah, am)
	a1 = am - ah
	a2 = 360 - am + ah
*/

class Solution {
public:
    double angleClock(int h, int m) {
        double ah = calcAngle(h, m);
		double am = calcAngle(m);
		if (ah > am) {
			swap(ah, am);
		}
		double a1 = am - ah;
		double a2 = 360 - am + ah;
		return min(a1, a2);
    }
	
private:
	double calcAngle(int h, int m) {
		if (h == 12) h = 0;
		return double(h)/12. * 360 + double(m) / 60.0 * 30;
	}
	
	double calcAngle(int m) {
		return m * 6;
	}
	
};