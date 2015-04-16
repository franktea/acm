/*
 * 378.cpp
 *
 *  uva 378 Intersecting Lines
 *
 *  Created on: Feb 27, 2015
 *      Author: franktang
 */

#include <iostream>
#include <limits> // std::numeric_limits<double>::epsilon()
#include <cmath>
#include <utility>      // std::pair
#include <algorithm>
#include <iomanip>

using namespace std;

inline bool EqualDouble(double a, double b)
{
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

// line ax+by+c=0
// if b != 0, let b=1
// if b == 0, let a=1
class Line
{
public:
    // 共线、平行、相交
    enum LINES_TYPE {COLLINEAR, PARALLEL, INTERSECTING};

    LINES_TYPE ToAnother(Line& rhs)
    {
        if(EqualDouble(a_, rhs.a_) && EqualDouble(b_, rhs.b_) &&
                EqualDouble(c_, rhs.c_))
        {
            return COLLINEAR;
        }

        if(EqualDouble(a_, rhs.a_) && EqualDouble(b_, rhs.b_))
        {
            return PARALLEL;
        }

        return INTERSECTING;
    }

    std::pair<double, double> CrossingPoint(Line& rhs) // 求交点
    {
        if(EqualDouble(a_, 0))
        {
            return std::make_pair((rhs.b_*c_-rhs.c_)/rhs.a_, -c_);
        }

        if(EqualDouble(rhs.a_, 0))
        {
            return std::make_pair((b_*rhs.c_-c_)/a_, -rhs.c_);
        }

        if(EqualDouble(b_, 0))
        {
            return make_pair(-c_, (rhs.a_*c_-rhs.c_)/rhs.b_);
        }

        if(EqualDouble(rhs.b_, 0))
        {
            return make_pair(-rhs.c_, (a_*rhs.c_ - c_)/b_);
        }

        return std::pair<double, double>((rhs.c_-c_)/(a_-rhs.a_),
                (rhs.a_*c_ - a_*rhs.c_)/(a_-rhs.a_));
    }
public:
    Line(double x1, double y1, double x2, double y2)
    {
        a_ = y2 - y1;
        b_ = x1 - x2;
        c_ = x2*y1 - x1*y2;

        if(EqualDouble(b_, 0)) // b=0， 平行于x轴
        {
            b_ = 0;
            c_ /= a_;
            a_ = 1;
        }
        else if(EqualDouble(a_, 0))
        {
            a_ = 0;
            c_ /= b_;
            b_ = 1;
        }
        else
        {
            a_ /= b_;
            c_ /= b_;
            b_ = 1;
        }

//        cout<<"line from "<<x1<<", "<<y1<<", "<<x2<<", "<<y2<<" is("<<a_<<", "<<b_<<
//                ", "<<c_<<")"<<endl;
    }
private:
    void Exchange(Line& rhs)
    {
        std::swap(a_, rhs.a_);
        std::swap(b_, rhs.b_);
        std::swap(c_, rhs.c_);
    }
private:
    double a_;
    double b_;
    double c_;
};

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
    cout<<"INTERSECTING LINES OUTPUT\n";
    int case_count;
    cin>>case_count;
    while(case_count--)
    {
        double x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        Line line1(x1, y1, x2, y2);
        cin>>x1>>y1>>x2>>y2;
        Line line2(x1, y1, x2, y2);
        switch(line1.ToAnother(line2))
        {
        case Line::COLLINEAR:
            cout<<"LINE\n";
            break;
        case Line::PARALLEL:
            cout<<"NONE\n";
            break;
        case Line::INTERSECTING:
        {
            auto point = line1.CrossingPoint(line2);
            cout<<"POINT "<<std::fixed<<std::setprecision(2)<<point.first<<" "<<point.second<<"\n";
            break;
        }
        }
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
