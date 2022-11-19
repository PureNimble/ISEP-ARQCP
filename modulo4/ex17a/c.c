unsigned int greater_date(unsigned int date1, unsigned int date2){	
		
	char month1 = (char) date1;				// First byte = month1
	char month2 = (char) date2;				// First byte = month2
	
	short year1 =(short) (date1 >> 8);		// Remove First 1 byte. The new First 2 bytes = year1
	short year2 =(short) (date2 >> 8);		// Remove First 1 byte. The new First 2 bytes = year2

	char day1 = (char) (date1 >> 24);		// Remove First 3 bytes. The new First 1 byte = day1
	char day2 = (char) (date2 >> 24); 		// Remove First 3 bytes. The new First 1 byte = day2


	if(year1 > year2){						// Check if year 1 is greater
		return date1;						// return date 1
	}
	else if(year1 < year2){					// Check if year 2 is greater
		return date2;						// return date 2
	}
	if(month1 > month2){					// Check if month 1 is greater
		return date1;						// return date 1
	}
	else if(month1 < month2){				// Check if month 2 is greater
		return date2;						// return date 2
	}
	if(day1 > day2){						// Check if day 1 is greater
		return date1;						// return date 1
	}
	else if(day1 < day2){					// Check if day 2 is greater
		return date2;						// return date 2
	}
	return date1;
}
