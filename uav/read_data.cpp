#include "read_data.h"
using namespace std;
read_data::read_data(string filename): filename(filename), parsedCsv(parsedCsv), no_of_addresses(no_of_addresses){ read_csv(filename); };
read_data::read_data() : filename(filename)
{
	filename = "postal_data.txt";
	read_csv(filename);
}
read_data::~read_data() {};

void read_data::read_csv(string filename) 
{

	fstream file;
	
	file.open(filename, fstream::in);

	if (!file)
	{
		std::cerr << "File could not be opened !\n";
		exit(0);
	}

	std::string line;
	while (getline(file, line))
	{
		std::stringstream lineStream(line);
		string cell;
		vector<string> parsedRow;
		while (getline(lineStream, cell, ','))
		{
			parsedRow.push_back(cell);
		}
		parsedCsv.push_back(parsedRow);
	}
	file.close();

}

void read_data::fill_data()
{
	this->no_of_addresses = parsedCsv.size();
	if (no_of_addresses <= 0) {
		cout << "File is empty";
		exit(0);
	}
	data.resize(no_of_addresses);
	for (size_t i = 0; i < no_of_addresses; i++) {
		data[i].post_code = parsedCsv[i][0];
		data[i].x_coord = stoi(parsedCsv[i][1]);
		data[i].y_coord = stoi(parsedCsv[i][2]);
		data[i].num = i;
	}
	parsedCsv.clear();
}

const static unordered_map<string, int> string_to_int
{
	{"Post_codes", 1},
	{"X_values", 2},
	{"Y_values", 3},
	{"All", 4}
};

void read_data::print_data(string type)
{
	if (!string_to_int.count(type)) {
		cout << "Invalid entry try one of the following: Post_codes, X_values, Y_values, All";
		exit(0);
	}
	switch (string_to_int.at(type)) {
	case 1:
		printf("Postcodes\n");
		for (size_t i = 0; i < data.size(); i++)
			cout << data[i].post_code << "\n";
		break;
	case 2:
		printf("X_values\n");
		for (size_t i = 0; i < data.size(); i++)
			cout << data[i].x_coord << "\n";
		break;
	case 3:
		printf("Y_values\n");
		for (size_t i = 0; i < data.size(); i++)
			cout << data[i].y_coord << "\n";
		break;
	case 4:
		printf("Entire dataset\n");
		printf("Postcodes, X_values, Y_values\n");
		for (size_t i = 0; i < data.size(); i++)
			cout << data[i].post_code << ",\t" << data[i].x_coord <<  ",\t\t" << data[i].y_coord << "\n";
		break;
	}

}
