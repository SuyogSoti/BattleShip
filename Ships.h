#ifndef SHIPS_H
#define SHIPS_H

#include <string>
#include <vector>

class Ships{
	private:
		std::string name;
		std::vector< std::vector<int> > positions;
		int length;
		void setSize(int size);
		void setName(std::string name);

	public:
		Ships(std::string name);
		Ships(std::string name, int size);
		int getSize();
        void resetLocation();
		std::string getName();
		void addPoints(std::vector< int > points);
};


#endif //SHIPS_H