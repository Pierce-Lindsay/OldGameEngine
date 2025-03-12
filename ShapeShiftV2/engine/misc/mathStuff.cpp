#include "mathStuff.h"


//std::mt19937 RNGSEED{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };

//returns in radians

glm::vec2 findLower(float a, float b)
{
	if(a < b)
	return glm::vec2{ a, b };
	else
	return glm::vec2{ b, a };
}
math::line::line()
{

}

math::line::line(glm::vec2 p1, glm::vec2 p2, std::string inequality)
	:inequality{ inequality }, endPoint1(p1), endPoint2(p2)
{
	if (p2.x != p1.x)
	{
		slope = (p2.y - p1.y) / (p2.x - p1.x);
		intercept = p1.y - (slope * p1.x);
	}
	else
	{
		verticalLine = true;
		slope = 10000000000000.0f;
		intercept = 0.0f;
	}
	Xbounds = findLower(p1.x, p2.x);
	Ybounds = findLower(p1.y, p2.y);


}

void math::line::translate(glm::vec2 velocity)
{
	Xbounds += glm::vec2{velocity.x, velocity.x};
	Ybounds += glm::vec2{ velocity.y, velocity.y };

	endPoint1 += velocity;
	endPoint2 += velocity;

	if (!verticalLine)
	{
		intercept -= velocity.x * slope;
		intercept += velocity.y;
	}
}

math::line math::getPerpendicularAtPoint(line l, glm::vec2 p)
{
	math::line perpendicular;
	if (l.verticalLine)
	{
		perpendicular.slope = 0.0f;
		perpendicular.intercept = p.y;
		perpendicular.Xbounds = glm::vec2(-1000000000000, 10000000000000);

	}
	else if (l.slope == 0.0f)
	{
		perpendicular.verticalLine = true;
		perpendicular.Xbounds = glm::vec2(p.x, p.x);
	}
	else
	{
		perpendicular.slope = (-1.0f / l.slope);
		perpendicular.Xbounds = glm::vec2(-1000000000000, 10000000000000);
		perpendicular.intercept = p.y - (perpendicular.slope * p.x);
	}
	perpendicular.Ybounds = glm::vec2(-1000000000000, 10000000000000);

	return perpendicular;
}



















//this doesn't work lol
/*
math::line math::getParrallelAtPoint(line l, glm::vec2 p)
{
	line parrallel;
	parrallel.slope = l.slope;
	//parrallel.intercept = l.intercept;
	if (l.verticalLine)
	{
		parrallel.verticalLine = true;
		parrallel.Xbounds = l.Xbounds;
		//stupid solution to boundless
		parrallel.Ybounds = glm::vec2(-1000000000.0f, 1000000000.0f);
	}
	else
	{
		parrallel.Xbounds = glm::vec2(-100000000000.0f, 10000000000.0f);
		parrallel.Ybounds = glm::vec2(-100000000000.0f, 10000000000.0f);
	}
		
	return parrallel;
}
*/



std::string math::swapInequality(std::string ineq)
{
	if (ineq == "=")
		return "=";
	else if (ineq == "<=")
		return ">=";
	else if (ineq == ">=")
		return "<=";
	else if (ineq == ">")
		return "<";
	else
		return ">";
}

bool math::pointOnInequality(glm::vec2 p, line ln)
{
	//note: in the from of y = mx + b, so for a normal line, if p plugged in satisfies, return true
	float r;
	float l;




	if (!ln.verticalLine)
	{
		r = (p.x * ln.slope) + ln.intercept;
		l = p.y;
	}
		
	else
	{
		r = ln.Xbounds.x;
		l = p.x;
	}
		
	
	//lg::printP(l);
	//lg::printP(" ");
	//lg::printP(ln.inequality);
	//lg::printP(" ");
	//lg::printL(r);
	//lg::printL("////////////////////////////");
	
	if (ln.inequality == "=")
	{
		if (l == r )
			return true;
		else
			return false;
	}
	else if (ln.inequality == ">=")
	{
		if (l >= r)
			return true;
		else
			return false;
	}
	else if (ln.inequality == "<=")
	{
		if (l <= r)
			return true;
		else
			return false;
	}
	else if (ln.inequality == ">")
	{
		if (l > r)
			return true;
		else
			return false;
	}
	else
	{
		if (l < r)
			return true;
		else
			return false;
	}
}

math::intersection math::intersectionPoint(line l1, line l2)
{
	intersection interPoint;
	interPoint.exists = true;
	interPoint.sameLine = false;
	float x;
	float y;

	//solve the system of equations
	if (l1.verticalLine && l2.verticalLine)
	{
		if (l1.Xbounds.x == l2.Xbounds.x)
		{
			interPoint.sameLine = true;
			return interPoint;
		}
		else
		{
			interPoint.exists = false;
			return interPoint;
		}
	}
	else if (l1.slope == l2.slope)
		 {
			if (l1.intercept == l2.intercept)
			{
				interPoint.sameLine = true;
				return interPoint;
			}
			else
			{
				interPoint.exists = false;
				return interPoint;
			}
	}



	//y = m1x + b1
	//- y = m2x + b2
	// 0 = x(m1 - m2) + (b1-b2)
	//= -(b1-b2)/(m1-m2) = x
	//y1 =  m1x + b1
	//y2 = m2x + b2
	if (l1.verticalLine)
	{
		x = l1.Xbounds.x;
		y = l2.slope * x + l2.intercept;
	}
		

	else if (l2.verticalLine)
	{
		x = l2.Xbounds.x;
		y = l1.slope * x + l1.intercept;
	}
	else
	{
		x = -(l1.intercept - l2.intercept) / (l1.slope - l2.slope);
		y = (l1.slope * x) + l1.intercept;
	}


	//now we have our point, so see if its in the bounds to see if it actually exists
	if (x >= l1.Xbounds.x && x <= l1.Xbounds.y
		&& x >= l2.Xbounds.x && x <= l2.Xbounds.y
		&& y >= l1.Ybounds.x && y <= l1.Ybounds.y
		&& y >= l2.Ybounds.x && y <= l2.Ybounds.y)
	{
		interPoint.point = glm::vec2(x, y);
		return interPoint;
	}
	else
	{
		interPoint.exists = false;
		return interPoint;
	}
}





math::Polygon::Polygon(std::vector <glm::vec2> points)
{
	createShapeWithPoints();
	centerPos = findCenterPosWithPoints();
	size = glm::vec2(1.0f, 1.0f);
}
math::Polygon::Polygon(std::vector <glm::vec2> points, glm::vec2 pos)
{
	createShapeWithPoints();
	centerPos = findCenterPosWithPoints(); 
	setPos(pos);
	size = glm::vec2(1.0f, 1.0f);
}
math::Polygon::Polygon(glm::vec2 pos, glm::vec2 size)
{

}
math::Polygon::Polygon(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 p4)
{

}
math::Polygon::Polygon(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3)
{

}




/*
*creates a vector of lines for the polygon where lines are created by the below operations
* points are assumed to be connected in the order they are provided
* for example: points[last element] --- points[0] --- points[1]...
* a line is a connection between element 1 and element 2
*/
void math::Polygon::createShapeWithPoints()
{
	int secondPointTracker = -1;
	for (int i = 0; i < points.size(); i++)
	{
		glm::vec2 p1;
		glm::vec2 p2 = points[i];
		if (secondPointTracker == -1)
			p1 = points[points.size() - 1];
		else
			p1 = points[secondPointTracker];


		lines.push_back(math::line(p1, p2));
		secondPointTracker++;
	}
}


/*
* given a vector of points, finds the center of that object and uses that as the center
* determined by centerPoint((Max x + Min x)/2.0, (Max y + Min y)/2.0)
*/
glm::vec2 math::Polygon::findCenterPosWithPoints()
{
	float xMax = points[0].x;
	float xMin = points[0].x;
	float yMax = points[0].y;
	float yMin = points[0].y;
	for (auto& e : points)
	{
		if (e.x < xMin)
			xMin = e.x;
		if (e.x > xMax)
			xMax = e.x;
		if (e.y < yMin)
			yMin = e.y;
		if (e.y > yMax)
			yMax = e.y;
	}

	glm::vec2 center{ (xMax + xMin) / 2.0f, (yMax + yMin) / 2.0f };
	return center;
}



/*
* translates the polygon by the given velocity by moving all of the points and lines and center pos
*/
void math::Polygon::translate(glm::vec2 v)
{
	for (auto& e : points)
	{
		e += v;
	}

	for (auto& e : lines)
	{
		e.translate(v);
	}
	centerPos += v;
}


/*
* translates the polygon to the given position by moving all of the points and lines and center pos
*/
void math::Polygon::setPos(glm::vec2 p)
{
	glm::vec2 delta = p - centerPos;
	translate(delta);
}


/*
* rotates the polygon in degrees, does this in three steps:
* moves the polygon so its center is at 0, 0
* rotates all points and lines about the center with the given rotation amount
* then translates the shape back to the centerpos it was located at
*/
void math::Polygon::rotate(float rot)
{
	//first save the current pos
	glm::vec2 actualPos = centerPos;
	//translate
	setPos(glm::vec2(0.0f, 0.0f));

	glm::mat4 rotMat = glm::mat4(1.0f);
	rotMat = glm::rotate(rotMat, glm::radians(rot), glm::vec3(0.0f, 0.0f, 1.0f));

}







const std::vector <math::line>& math::Polygon::getLines()
{
	return lines;
}
const std::vector <glm::vec2>& math::Polygon::getPoints()
{
	return points;
}





float math::findPolarTheta(glm::vec2 pos)
{
	float angle = (math::findComponentVectorAngle(pos));
	if (pos.x < 0 && pos.y < 0)
		angle += 3.14;
	else if (pos.x < 0)
		angle = 3.14 - angle;
	else if (pos.y < 0)
		angle = 6.28 - angle;

	return angle;
}
float math::findDistance(glm::vec2 pos1, glm::vec2 pos2)
{
	return float(sqrt(pow(double(pos2.x - pos1.x), 2.0) + pow(double(pos2.y - pos1.y), 2.0)));
}

float math::findVectorValue(glm::vec2 components)
{
	return float((sqrt(pow(double(components.x), 2.0) + pow(double(components.y), 2.0))));
}

float math::findComponentVectorAngle(glm::vec2 components)
{
	//returns in degrees
	if (components.x == 0)
	{
		return 3.141f / 2.0f;
	}

	return abs((atan(components.y / components.x)));
}






glm::vec2 math::solveQuadratic(float a, float b, float c)
{
	//-bplusormiunus sqrt(b^2-4ac)/2a

	//two equations
	float componentscriminate = float(pow(b, 2.0) - (4 * a * c));

	if (componentscriminate < 0)
	{
		//throw "unreal answer";
		return glm::vec2(0.0f, 0.0f);


	}
	else if (componentscriminate == 0)
	{
		float ans = -b / (2 * a);
		return glm::vec2(ans, ans);
	}
	else
	{
		float ans1 = (-b + sqrt(componentscriminate)) / (2 * a);

		float ans2 = (-b - sqrt(componentscriminate)) / (2 * a);

		return(glm::vec2(ans1, ans2));
	}

}

//int math::generateRandomNum(int min, int max)
//{
//	std::uniform_int_distribution die{ min, max };
//	return die(RNGSEED);
//}
