/*
* Hijacked by Elo'him@ForgottenGods
* Repurposed date: July 21, 2011
* This definition file seemed to be used for a
* defunt alchemy system that was out of play.
* I added to it not to break the already in place
* system and defined materials for a managed
* material system
*/ 
 
#define MATERIAL_PROPS ({ "density","hardness" })

#define MATERIAL_TYPES ({ "fluid","stone","metal","wood",\
"textile", "leather", "meat", "botany", "mineral", "gas" })

#define MATERIAL_METAL ({\
"aluminium", "bismuth", "cobalt", "copper", "gallium",\
"gold", "indium", "iron", "dark iron", "lead", "magnesium",\
"mercury", "mythril", "nickel", "potassium", "plutonium", \
"rhodium", "silver", "steel", "dark steel", "titanium", "tin",\
"uranium", "zinc", "zirconium" })

#define MATERIAL_ALL MATERIAL_TYPES+MATERIAL_METAL