#include<fstream>

using namespace std;

#include "purchaseOrder.h"

void generate(requisition r, po p)
	{

		ofstream fout;

		//retreving system date and time
		time_t current = time(0);
		char* dt = ctime(&current);


		//opening the Current_PO.txt file in which PO details are stored 


		fout.open("Current_PO.txt");

		//Generating the PO and storing it in the Current_PO.txt file in a formatted manner


		fout << "\t\t\t  Purchase Order#: " << p.po_no << "\n";
		fout << "\t\t\t________\n\n";
		fout << "Requisition#: " << r.req_no << "\t\t\t\tIssue Date: " << dt << "\n\n";
		if (r.item_code >= 1 && r.item_code <= 10)
			fout << "Supplier: " << "SKS Inc\n\n";
		else if(r.item_code>=11 && r.item_code<=20)
			fout << "Supplier: " << "KC Spare Parts Ltd.\n\n";
		else
			fout << "Supplier: " << "Other(_____________)\n\n";


		fout << "Delivery Date: " << r.delivery_date << "\n\n";
		fout << "----------------------------------------------------------------------------------------------------------------------\n";
		fout << "                                            *Line Items*                                                            \n";
		fout << "----------------------------------------------------------------------------------------------------------------------\n";
		fout << "Item Code\t\tQuantity\t\tPrice\t\tTotal\n";
		fout << "___\t\t___\t\t_\t\t___\n\n";
		fout << " " << r.item_code << "\t\t\t " << r.qty << "\t\t\t";
		if (r.item_code >= 1 && r.item_code <= 20)
		{
			fout << " " << price_list[r.item_code - 1] << "\t\t\t " << price_list[r.item_code - 1] * r.qty << "\n\n\n\n";

		}
		else
		{
			fout << "_\t\t\t___\n\n\n\n";
		}

	
		fout.close();




	}
