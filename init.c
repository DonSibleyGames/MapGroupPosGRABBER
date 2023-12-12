// DayZ Editor just needs an Empty init.c to function
// add whatever you'd like here for your own custom scripts :)

	void findLocations()
	{
		array<Object> objects = new array<Object>;
		array<CargoBase> proxy_cargos = new array<CargoBase>;
		FileHandle file = OpenFile("$profile:foundObj.txt", FileMode.APPEND);
		GetGame().GetObjectsAtPosition("7500 0 7500", 15000, objects, proxy_cargos);
		
		for(int i = 0; i < objects.Count(); i++)
		{
			
				string whatiwant = "misc_chickencoop.p3d"; //<<<<<<Place what you want to get mgp here
			
				vector pos = objects.Get(i).GetPosition();
				vector ori = objects.Get(i).GetOrientation();
				float scale = objects.Get(i).GetScale();
				string nearObj = objects.Get(i).GetType();
				string p3dpath = objects.Get(i).GetShapeName();
				string p3dName = objects.Get(i).GetDebugName();
				
				TStringArray strs = new TStringArray;
				p3dpath.Split("\\", strs );
				
				float az;
				
				for(int x = 0; x < strs.Count(); x++)
					{
						if(strs[x] == whatiwant){	

							if(ori[0] <= -90){
								az = -270 - ori[0];
							 }else{
								az = 90 - ori[0];
							 }

					FPrintln(file, "<group name=\"" + strs[x] + "\" pos=\"" + pos[0] + " " + pos[1] + " " + pos[2] + "\"" + " rpy=\"" + ori[2] + " " + ori[1] + " " + ori[0] + "\" a=\"" + az + "\" />");
						  
				}
			}
		}
		CloseFile(file);
	}



void main()
{
 //GetCEApi().ExportProxyData("10000 0 10000", 10000)
//GetCEApi().ExportClusterData();	
findLocations();
 
}
