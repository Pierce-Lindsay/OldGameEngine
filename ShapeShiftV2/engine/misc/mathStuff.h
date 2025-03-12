#pragma once
#include <cmath>
#include <chrono>
#include <random>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Logger.h"

namespace math
{
	struct line
	{
		//<, >, <=, >=
		bool verticalLine = false;
		std::string inequality = "=";
		float slope;
		float intercept;
		glm::vec2 Xbounds;
		glm::vec2 Ybounds; // only applies in inequalities
		glm::vec2 endPoint1;
		glm::vec2 endPoint2;

		line(glm::vec2 p1, glm::vec2 p2, std::string inequality = "=");
		line();
		//line(glm::vec2 point, float slope)
		void translate(glm::vec2 velocity);
	};

	struct intersection
	{
		glm::vec2 point;
		bool exists;
		bool sameLine;
	};


	class Polygon
	{
	private:
		std::vector<math::line> lines;
		std::vector <glm::vec2> points;
		glm::vec2 centerPos{ 0.0f, 0.0f };
		glm::vec2 size{ 1.0f, 1.0f };

		/*
	*creates a vector of lines for the polygon where lines are created by the below operations
	* points are assumed to be connected in the order they are provided
	* for example: points[last element] --- points[0] --- points[1]...
	* a line is a connection between element 1 and element 2
	*/
		void createShapeWithPoints();

		/*
		* given a vector of points, finds the center of that object and uses that as the center 
		* determined by centerPoint((Max x + Min x)/2.0, (Max y + Min y)/2.0)
		*/
		glm::vec2 findCenterPosWithPoints();

	public:

		/*
		* a constructor that taces in a vector of points
		* points are assumed to be connected in the order they are provided
		* for example: points[last element] --- points[0] --- points[1]...
		* pos is determined from centerpoint of these points
		*/
		Polygon(std::vector <glm::vec2> points);

		/*
		* a constructor that taces in a vector of points, and pos
		* points are assumed to be connected in the order they are provided
		* for example: points[last element] --- points[0] --- points[1]...
		* moved to given pos after orginal pos is determined from centerpoint of these points
		*/
		Polygon(std::vector <glm::vec2> points, glm::vec2 pos);

		/*
		* a rectangle, created from the size perameter and then moved to given pos
		*/
		Polygon(glm::vec2 pos, glm::vec2 size);


		/*
		* a rectangle, with given points connected in the form of:
		* p4-p1-p2-p3-p4
		*/
		Polygon(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 p4);

		/*
		* a triangle, with given points connected in the form of:
		* p3-p1-p2-p3
		*/
		Polygon(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3);

		/*
		* translates the polygon by the given velocity by moving all of the points and lines and center pos
		*/
		void translate(glm::vec2 v);


		/*
		* translates the polygon to the given position by moving all of the points and lines and center pos
		*/
		void setPos(glm::vec2 p);


		/*
		* rotates the polygon in degrees, does this in three steps:
		* moves the polygon so its center is at 0, 0
		* rotates all points and lines about the center with the given rotation amount
		* then translates the shape back to the centerpos it was located at
		*/
		void rotate(float rot);

		const std::vector <math::line>& getLines();
		const std::vector <glm::vec2>& getPoints();



	};
	//	polygon();
	

	//std::mt19937 RNGSEED;
	//returns in radians
	//line getParrallelAtPoint(line l, glm::vec2 p);
	line getPerpendicularAtPoint(line l, glm::vec2 p);
	std::string swapInequality(std::string ineq);
	bool pointOnInequality(glm::vec2 p, line ln);
	intersection intersectionPoint(line l1, line l2);
	float findPolarTheta(glm::vec2 pos);
	float findDistance(glm::vec2 pos1, glm::vec2 pos2);
	float findVectorValue(glm::vec2 components);
	float findComponentVectorAngle(glm::vec2 components);
	//int generateRandomNum(int min, int max);
	glm::vec2 solveQuadratic(float a, float b, float c);
}