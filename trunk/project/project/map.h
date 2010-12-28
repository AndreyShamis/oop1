#pragma once
#include <iostream>
#include <vector>
class map
{
public:
	static map* getInstance();
	static map* _instance;

	char getCellValue(const int &Y,const int &X)const;
	void setCellValue(const int &Y,const int &X,const char newValue);

private:

	std::vector< std::vector<char> > _map;


};


    //vector< vector<int> > ph;

    //vector<int> p;
    //p.push_back(1);
    //p.push_back(2);
    //p.push_back(3);

    //vector<int> q;
    //q.push_back(10);
    //q.push_back(20);
    //q.push_back(30);
    //q.push_back(40);

    //ph.push_back(p);
    //ph.push_back(q);

    //for (vector< vector<int> >::size_type u = 0; u < ph.size(); u++) {
    //    for (vector<int>::size_type v = 0; v < ph[u].size(); v++) {
    //        cout << ph[u][v] << " ";
    //    }
    //    cout << endl;
    //}