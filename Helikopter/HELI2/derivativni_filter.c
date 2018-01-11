//(k), (k-1), (k-2)
float[3] speed = {0.0, 0.0, 0.0};

//(k-1),(k-2)
float[2] position = {0.0, 0.0};

void Get_Speed(float* speed, float* position){
	
	//save the new speed value to speed pointer and move past steps
	float temp_speed;
	int i;
	
	//calculate speed(k)
	temp_speed = *(speed + 1)*1.793 - *(speed + 2)*0.8076 + (*position - *(position + 1))*14.18;
	
	//put speed(k) on the beginnig of speed array and move past speeds
	*(speed + 2) = *(speed + 1);
	*(speed + 1) = *(speed);
	*(speed) = temp_speed;
	
	return;	
}