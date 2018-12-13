#include "std_lib_facilities.h"
int main();

void errorline();

int main () 
{
	
		double sum = 0, smallest = numeric_limits<float>::max(), largest;
		vector<double> values;

	
		cout << "[!] Ervenyes formak : cm, in, ft, m.\n";
		cout << "[!] Peldak: '3m', '4in', '9ft', '20cm'.\n";
		cout << "[!] Az osszeg kiirasahoz nyomj entert '|'.";

	
	while(true) 
	{
			cout << "\n> Irj be egy erteket: ";

		
			bool isValid;
			double input = 0.0;
			string unit = "";

			if(cin >> input >> unit) 
		{
			isValid = true;
		
		} 
	else 
		{
			isValid = false;
			cin.clear();
			cin.ignore();
			break;
		
		}

			double converted = 0;

		
	if(isValid) 
		{
			if(unit == "cm") { converted = input/100.0; }
			else if(unit == "in") { converted = (input * 2.54)/100.0; }
			else if(unit == "ft") { converted = ((input * 12.0 * 2.54)/100.0); }
			else if(unit == "m") { converted = input; }
			else { errorline(); continue;
		}

	if(converted <= smallest) 
		{
			smallest = converted;
			cout << "+ smallest so far\n";
		}

	if(converted > largest) 
		{
			largest = converted;
			cout << "+ largest so far\n";
		}

			values.push_back(converted);
			sum += converted;
		}
	}

	
	if(values.size() > 0) 
	{
		
		sort(values.begin(), values.end());

		
		cout << "\n================SUMMARY====================\n";
		cout << "Legkisebb ertek: " << smallest << "m\n";
		cout << "Legnagyobb ertek: " << largest << "m\n";
		cout << "Azok osszege: " << sum << "m\n";
		cout << "# of inputs: " << values.size() << "\n";
		cout << "Növekvő sorrendben az ertekek egyesevel:\n";

	for(long unsigned int i=0; i < values.size(); i++) 
		{
			cout << "- " << values[i] << "m\n";
		}
		cout << "\n===========================================\n";
	}
	
	return 0;
}

void errorline() 
{
	cout << "[!] HIBA: Rossz formatum." << endl;
}
