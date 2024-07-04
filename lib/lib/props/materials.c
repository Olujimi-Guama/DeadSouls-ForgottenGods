//	Elohim@ForgottenGods 20110726

#include <materials.h>

private mapping ItemMaterials;

SetMaterials(mapping mats){
	
	int count, cent;
	string *mval;
	
	
	if( !mapp(mats)  )
		error("Invalid Mapping in SetMaterials()\n");
	if( mats== ([ ]) ) // this isn't being recognized -elo
		error("Empty Mapping not allowed in SetMaterials()\n");
	
	// first we want to make sure that mats equal 100%
	mval = values(mats);
	count = sizeof(mval);
	
	while (count) {
	
		count--;
		cent += mval[count];
	}
	// if it doesn't equal 100% toss it
	
	if(cent != 100) 
		error("Total must be 100(%) in SetMaterials()\n");
		
		else {
			
	
	mval = keys(mats);
	count = sizeof(mval);
	
	while (count) {
	
		count--;		
		
		if( member_array(mval[count], MATERIAL_ALL ) == -1 )
			error("Unlisted Material not allowed in SetMaterials()\n");
		}
	
			ItemMaterials = mats;
		}
}


mapping GetMaterials(){
	return ItemMaterials;
	}