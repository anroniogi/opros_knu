
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "SLAMComp.h"
#include "device/OprosPrintMessage.h"

//
// constructor declaration
//
SLAMComp::SLAMComp()
{
	error = 0;//kitech
	lastError = OPROS_SUCCESS;

	ptrMobileControllerService = NULL;

	ptrLaserScannerService = NULL;


	
	portSetup();
}

//
// constructor declaration (with name)
//
SLAMComp::SLAMComp(const std::string &name):Component(name)
{
	error = 0;//kitech
	lastError = OPROS_SUCCESS;

	ptrMobileControllerService = NULL;

	ptrLaserScannerService = NULL;


	
	portSetup();
}

//
// destructor declaration
//

SLAMComp::~SLAMComp() {
}
SLAMComp::MapT SLAMComp::GetMap()
{
	//user code hear
	//SelectBestParticle();
	error = 0;
	if (globalMap.get() != nullptr) {
		std::vector< std::vector<double> > map;
		double x, y;
		globalMap->GetMap(map, x, y);
		return map;
	}

	error = -1;
	return std::vector< std::vector<double> >();
}

OPRoS::MobilePositionData SLAMComp::GetPosition()
{
	//user code hear
	//SelectBestParticle();

	error = 0;
	if (globalMap.get() != nullptr) {
		std::cout << "SLAMComp GetPosition1 : " << currentPosition.x <<currentPosition.y << currentPosition.theta<< std::endl;
		return currentPosition;
	}
	error = -1;
	std::cout << "SLAMComp GetPosition2 : " << currentPosition.x <<currentPosition.y << currentPosition.theta<< std::endl;

	return currentPosition;
}

void SLAMComp::ReStartSLAM()
{
	//user code hear
	for (unsigned int i=0; i<particles.size(); ++i) {
		particles[i] = VirtualRobot();
		particles[i].map = std::make_shared<GridBasedGlobalMap>(mapResolution);
		particles[i].map->SetUseUpdateOncePerScan(true);
		particles[i].map->SetUpdateParameters(logLikelihood_occupied, logLikelihood_free, minCellLogLikelihood, maxCellLogLikelihood);
	}
	isInitialized = false;
}

bool SLAMComp::IsIn(double x,double y)
{
	//user code hear
	//SelectBestParticle();
	error = 0;
	if (globalMap.get() != nullptr) {
		return globalMap->IsIn(x,y);
	}

	error = -1;
	return false;
}

double SLAMComp::GetCellOccProb(double x,double y)
{
	//user code hear
	error = 0;
	if (globalMap.get() != nullptr) {
		//error = globalMap->IsIn(x,y) ? 0 : -1;
		double data;
		error = globalMap->GetCellData(x,y,data) - 1;
		return 1 / (1 + exp(-data));
	}
	error = -1;
	return 0;
}

double SLAMComp::GetMapHeight()
{
	//user code hear
	//SelectBestParticle();

	error = 0;
	if (globalMap.get() != nullptr) {
		return globalMap->GetHeight();
	}
	error = -1;
	return -1.0;
}

double SLAMComp::GetMapWidth()
{
	//user code hear
	//SelectBestParticle();

	error = 0;
	if (globalMap.get() != nullptr) {
		return globalMap->GetWidth();
	}
	error = -1;
	return -1.0;
}

double SLAMComp::GetMapStartY()
{
	//user code hear
	//SelectBestParticle();

	error = 0;
	if (globalMap.get() != nullptr) {
		GridBasedGlobalMap::Point p = globalMap->GetMinCorner();
		return p[1];
	}
	error = -1;
	return -1.0;
}

double SLAMComp::GetMapStartX()
{
	//user code hear
	//SelectBestParticle();

	error = 0;
	if (globalMap.get() != nullptr) {
		GridBasedGlobalMap::Point p = globalMap->GetMinCorner();
		return p[0];
	}
	error = -1;
	return -1.0;
}

double SLAMComp::GetMapCellSize()
{
	//user code hear
	error = 0;
	if (globalMap.get() != nullptr) {
		return globalMap->GetCellSize();
	}
	error = -1;
	return -1.0;
}

bool SLAMComp::SaveMapFile(std::string fileName)
{
	//user code hear
	error = 0;
	if (globalMap.get() != nullptr) {
		return globalMap->SaveMapToBMP(fileName, currentPosition.x, currentPosition.y, currentPosition.theta);
	}
	error = -1;
	return false;
}

bool SLAMComp::LoadMapFile(std::string fileName)
{
	//user code hear
	error = 0;

	std::shared_ptr<GridBasedGlobalMap> newMap = std::make_shared< GridBasedGlobalMap >(mapResolution);
	newMap->SetUseUpdateOncePerScan(true);
	newMap->SetUpdateParameters(logLikelihood_occupied, logLikelihood_free, minCellLogLikelihood, maxCellLogLikelihood);
	if (newMap->LoadMapFromBMP(fileName, currentPosition.x, currentPosition.y, currentPosition.theta)) {
		for (unsigned int i=0; i<particles.size(); ++i) {
			particles[i] = VirtualRobot();
			particles[i].map = std::make_shared<GridBasedGlobalMap>(mapResolution);
			(*particles[i].map) = (*newMap);
		}
		SelectBestParticle();

		return true;
	}

	error = -1;
	return false;
}

ReturnType SLAMComp::GetError()
{
	//user code hear
	//return error; // kitech
	return lastError;
}

OPRoS::Property SLAMComp::GetProperty()
{
	//user code hear
	return parameter;
}

ReturnType SLAMComp::SetProperty(OPRoS::Property parameter)
{
	//user code hear
	this->parameter = parameter;
	//return true;
	return lastError;
}

void SLAMComp::portSetup() {
	ProvidedServicePort *pa2;
	pa2=new SLAMServiceProvided(this);
	addPort("SLAMService",pa2);

	ptrMobileControllerService=new MobileControllerServiceRequired();
	addPort("MobileControllerService",ptrMobileControllerService);

	ptrLaserScannerService=new LaserScannerServiceRequired();
	addPort("LaserScannerService",ptrLaserScannerService);



	// export variable setup


}

// Call back Declaration
ReturnType SLAMComp::onInitialize()
{
	// user code here
	PrintMessage ("SLAMComp::onInitialize()\n");

	parameter.SetProperty(getPropertyMap());
	if (!LoadProperty()) return OPROS_FIND_PROPERTY_ERROR;

	globalMap = std::make_shared< GridBasedGlobalMap >(mapResolution);
//170825 mskim
	
	srand(time(NULL));

	error = 0;

	a1 = 5e-3;
	a2 = 1e-2;
	a3 = 1e-1;
	a4 = 1e-2;

	resamplingThreshold = 0.5;
	effectiveNumber = 0;
	minCellLogLikelihood = -2;
	maxCellLogLikelihood = 3.5;
	logLikelihood_occupied = 0.85;
	logLikelihood_free = -0.4;
	visitedCellLists.resize(NumberOfParticles);
	searchWindowSize = 3;
	doPrediction = false;

	useScanMatching = true;
	maxMatchingLinearStepLength = mapResolution;
	maxMatchingAngularStepLength = DEG2RAD(10);
	matchingFineDegree = 3;
	minLinearDistance = maxMatchingLinearStepLength/2;
	minAngularDistance = maxMatchingAngularStepLength/2;
	minRatioNumberValidPoint = 0.75;

#if DEBUG
	magnifyingScale = mapResolution*5e1;

#if SHOWALL
	for (int i=0; i<NumberOfParticles; ++i) {
		std::stringstream ss;
		ss<<i;
		cv::namedWindow("SLAMComp_DEBUG"+ss.str(),CV_WINDOW_AUTOSIZE);
	}
#else
	cv::namedWindow("SLAMComp_DEBUG0",CV_WINDOW_AUTOSIZE);
#endif
#endif

	particles.resize(NumberOfParticles);
	for (unsigned int i=0; i<particles.size(); ++i) {
		particles[i].map = std::make_shared<GridBasedGlobalMap>(mapResolution);
		particles[i].map->SetUseUpdateOncePerScan(true);
		particles[i].map->SetUpdateParameters(logLikelihood_occupied, logLikelihood_free, minCellLogLikelihood, maxCellLogLikelihood);
	}

	return OPROS_SUCCESS;
}

ReturnType SLAMComp::onStart()
{
	// user code here
/*
    //kitech
	startAngle = DEG2RAD(atof(ptrLaserScannerService->GetParameter().GetValue("StartAngle").c_str()));
	endAngle = DEG2RAD(atof(ptrLaserScannerService->GetParameter().GetValue("EndAngle").c_str()));
	sensorCount = (atoi(ptrLaserScannerService->GetParameter().GetValue("EndStep").c_str()) - atoi(ptrLaserScannerService->GetParameter().GetValue("StartStep").c_str())) / atoi(ptrLaserScannerService->GetParameter().GetValue("DeltaStep").c_str()) + 1;
	minRange = atof(ptrLaserScannerService->GetParameter().GetValue("MinimumRange").c_str());
	maxRange = atof(ptrLaserScannerService->GetParameter().GetValue("MaximumRange").c_str());
	sensorVariance = atof(ptrLaserScannerService->GetParameter().GetValue("Variance").c_str());
	sensorPosition.x = atof(ptrLaserScannerService->GetParameter().GetValue("X").c_str());
	sensorPosition.y = atof(ptrLaserScannerService->GetParameter().GetValue("Y").c_str());
	sensorPosition.theta = DEG2RAD(atof(ptrLaserScannerService->GetParameter().GetValue("Yaw").c_str()));
*/

	//170825 mskim
	
	startAngle = DEG2RAD(atof(ptrLaserScannerService->GetProperty().GetValue("StartAngle").c_str()));
	endAngle = DEG2RAD(atof(ptrLaserScannerService->GetProperty().GetValue("EndAngle").c_str()));
	sensorCount = (atoi(ptrLaserScannerService->GetProperty().GetValue("EndStep").c_str()) - atoi(ptrLaserScannerService->GetProperty().GetValue("StartStep").c_str())) / atoi(ptrLaserScannerService->GetProperty().GetValue("DeltaStep").c_str()) + 1;
	minRange = atof(ptrLaserScannerService->GetProperty().GetValue("MinimumRange").c_str());
	maxRange = atof(ptrLaserScannerService->GetProperty().GetValue("MaximumRange").c_str());
	sensorVariance = atof(ptrLaserScannerService->GetProperty().GetValue("Variance").c_str());
	sensorPosition.x = atof(ptrLaserScannerService->GetProperty().GetValue("X").c_str());
	sensorPosition.y = atof(ptrLaserScannerService->GetProperty().GetValue("Y").c_str());
	sensorPosition.theta = DEG2RAD(atof(ptrLaserScannerService->GetProperty().GetValue("Yaw").c_str()));
	
	return OPROS_SUCCESS;
}
	
ReturnType SLAMComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType SLAMComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType SLAMComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType SLAMComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType SLAMComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType SLAMComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType SLAMComp::onExecute()
{
	std::cout<<"SLAMComp::onExecute()"<<std::endl;
	// user code here

	//170825 mskim
	DoSLAMOneCycle();

	return OPROS_SUCCESS;
}
	
ReturnType SLAMComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType SLAMComp::onPeriodChanged()
{
	// user code here
	return OPROS_SUCCESS;
}


bool SLAMComp::LoadProperty()
{
	if (parameter.FindName ("NumberOfParticles") == false) {
		PrintMessage ("ERROR -> Can not found NumberOfParticles parameter\n");
		return false;
	}
	NumberOfParticles = atoi ((char *)parameter.GetValue("NumberOfParticles").c_str());
	PrintMessage ("<SLAMComp Parameter> NumberOfParticles : %d\n", NumberOfParticles);

	if (parameter.FindName ("MapResolution") == false) {
		PrintMessage ("ERROR -> Can not found MapResolution parameter\n");
		return false;
	}
	mapResolution = atof (parameter.GetValue ("MapResolution").c_str ());
	PrintMessage ("<SLAMComp Parameter> MapResolution : %.3lf\n", mapResolution);

	if (parameter.FindName ("MapOccProbThreshold") == false) {
		PrintMessage ("ERROR -> Can not found MapOccProbThreshold parameter\n");
		return false;
	}
	mapLogLikelihoodThreshold = atof (parameter.GetValue ("MapOccProbThreshold").c_str ());
	mapLogLikelihoodThreshold = log(mapLogLikelihoodThreshold) - log(1 - mapLogLikelihoodThreshold);
	PrintMessage ("<SLAMComp Parameter> MapOccProbThreshold : %.3lf\n", mapLogLikelihoodThreshold);

	return true;
}

void SLAMComp::DoSLAMOneCycle()
{
	std::cout<<"SLAMComp::DoSLAMOneCycle()"<<std::endl;
	//user code hear
	Localize();
	Mapping();
}

bool SLAMComp::Localize()
{
	std::cout<<"SLAMComp::Localize()"<<std::endl;
	//user code hear
	OPRoS::MobilePositionData position;
	if (ptrMobileControllerService) {
		position = ptrMobileControllerService->GetPosition();
		std::cout << "SLAMComp Localize Position : " << position.x <<position.y << position.theta<< std::endl;

		if (Predict(position) || !isInitialized) {
			if (ptrLaserScannerService) {
				auto sensorData = ptrLaserScannerService->GetSensorValue();
				if (sensorData.empty())
					return false;



				auto& laserData = sensorData.at(0).data; //auto& sensorData.data -> sensorData.at(0).data 전태경 수정
				//auto& laserData = sensorData.data;

			
				if (laserData.size() == sensorCount) {
#if DEBUG
					lastLaserData = laserData;
#endif
					int numValidPoint = 0;
					for (unsigned int i = 0; i < laserData.size(); ++i) {
						numValidPoint += (laserData[i] >= minRange && laserData[i] <= maxRange);
					}

					if (numValidPoint >= minRatioNumberValidPoint * sensorCount && ptrLaserScannerService->GetError() == OPROS_SUCCESS) {
						Update(laserData);
						isInitialized = true;
					}
				}
			}
		}
	}
	return false;
}

bool SLAMComp::Predict (OPRoS::MobilePositionData position)
{

	if (!doPrediction) {
		previousPosition = position;
		doPrediction = true;
		return true;
	}

	OPRoS::MobilePositionData delta (position.x - previousPosition.x, position.y - previousPosition.y, DeltaRad(position.theta, previousPosition.theta));
	double ang1 = DeltaRad (atan2(delta.y, delta.x), previousPosition.theta);
	double ang2 = DeltaRad (delta.theta, ang1);

	double deltaForward = sqrt(delta.x*delta.x + delta.y*delta.y);
	double deltaAngle = delta.theta;

	if (fabs(deltaForward) < minLinearDistance && fabs(deltaAngle) < minAngularDistance) {
		return false;
	}

	for (unsigned int i = 0, n = particles.size(); i < n; ++i) {
		VirtualRobot &vr = particles[i];

		double dang1 = (a1*fabs(ang1)+a2*deltaForward) * GaussRand();
		double dang2 = (a1*fabs(ang2)+a2*deltaForward) * GaussRand();
		double dtrans = (a4*(fabs(ang1)+fabs(ang2))+a3*deltaForward) * GaussRand();


		vr.position.x += (deltaForward+dtrans) * cos(vr.position.theta+ang1+dang1);
		vr.position.y += (deltaForward+dtrans) * sin(vr.position.theta+ang1+dang1);
		vr.position.theta += ang1 + dang1 + ang2 + dang2;
	}

	previousPosition = position;

	return true;
}

bool SLAMComp::Update (std::vector<double> sensorValue)
{
/*
	for (unsigned int i = 0, n = particles.size(); i < n; ++i) {
		VirtualRobot &vr = particles[i];
		visitedCellLists[i].clear();

		if (useScanMatching) {
			ScanMatching(vr, sensorValue);
			GetVisitedCellList(vr, sensorValue, visitedCellLists[i]);
		} else {
			vr.logLikelihood += GetLogLikelihood (vr, sensorValue, visitedCellLists[i]);
		}

		vr.position.theta -= ceil(vr.position.theta / 2 / M_PI - 0.5) * 2 * M_PI;
	}
//*/

	std::vector<std::thread> threads(particles.size());
	for (unsigned int i=0; i<particles.size(); ++i) {
		threads[i] = std::thread(&SLAMComp::UpdateOne, this, std::ref(sensorValue), i);
	}
	for (unsigned int i=0; i<particles.size(); ++i) {
		threads[i].join();
	}

	CalculateWeights();

	if (effectiveNumber <= resamplingThreshold * particles.size()) {
		Resampling ();
	}

	return false;
}

void SLAMComp::UpdateOne(std::vector<double> sensorValue, unsigned int i)
{

	VirtualRobot &vr = particles[i];
	visitedCellLists[i].clear();

	if (useScanMatching) {
		ScanMatching(vr, sensorValue);
		GetVisitedCellList(vr, sensorValue, visitedCellLists[i]);
	} else {
		vr.logLikelihood += GetLogLikelihood (vr, sensorValue, visitedCellLists[i]);
	}

	vr.position.theta -= ceil(vr.position.theta / 2 / M_PI - 0.5) * 2 * M_PI;
}

void SLAMComp::Resampling ()
{
	std::cout<<"SLAMComp::Resampling()"<<std::endl;

	std::vector<VirtualRobot> new_particles(particles.size());

	unsigned int n = 0, m = 0;
	for (double initp = 1.0*rand()/particles.size()/RAND_MAX, p=initp, cp=0; p<1+initp-0.5/particles.size(); p+=1.0/particles.size()) {
		while (cp < p) {
			cp += particles[n++].weight;
		}
		new_particles[m] = particles[n-1];
		new_particles[m].logLikelihood = 0;
		new_particles[m].map = std::make_shared<GridBasedGlobalMap>(mapResolution);
		(*new_particles[m].map) = (*particles[n-1].map);
		++m;
	}
	particles.swap (new_particles);
}

void SLAMComp::CalculateWeights()
{
	std::cout<<"SLAMComp::CalculateWeights()"<<std::endl;

	effectiveNumber = 0;
	double weightSum = 0.;

	double maxLogLikelihood = -std::numeric_limits<double>::max();
	for (unsigned int i=0; i<particles.size(); ++i) {
		maxLogLikelihood = maxLogLikelihood < particles[i].logLikelihood ? particles[i].logLikelihood : maxLogLikelihood;
	}

	for (unsigned int i=0; i<particles.size(); ++i) {
		particles[i].weight = exp((particles[i].logLikelihood - maxLogLikelihood) / sensorCount);
		weightSum += particles[i].weight;
	}

	for (unsigned int i = 0, n = particles.size(); i < n; ++i) {
		particles[i].weight /= weightSum;
		particles[i].weightSum += particles[i].weight;

		effectiveNumber += particles[i].weight * particles[i].weight;

		//std::cout<<i<<"th loglikelihood = "<<particles[i].logLikelihood<<", weight = "<<particles[i].weight<<std::endl;
	}
	effectiveNumber = 1 / effectiveNumber;
}

double SLAMComp::GetLogLikelihood (const VirtualRobot &vr, const std::vector<double> &laserData, VisitedCellList& visitedCellList)
{

	OPRoS::MobilePositionData sensorPos(sensorPosition);
	double c = cos(vr.position.theta);
	double s = sin(vr.position.theta);
	double tmp_x = sensorPos.x * c - sensorPos.y * s;
	double tmp_y = sensorPos.x * s + sensorPos.y * c;
	sensorPos.x = tmp_x + vr.position.x;
	sensorPos.y = tmp_y + vr.position.y;
	sensorPos.theta += vr.position.theta;

	double resolution = (endAngle - startAngle) / (sensorCount - 1);

	double l = 0;
	for (unsigned int i = 0; i < sensorCount; ++i) {
		double v = laserData[i];
		if (minRange <= v && v <= maxRange) {
			OPRoS::MobilePositionData ep (v * cos(sensorPos.theta + startAngle + i * resolution), v * sin(sensorPos.theta + startAngle + i * resolution), sensorPos.theta + startAngle + i * resolution);
			ep.x += sensorPos.x;
			ep.y += sensorPos.y;
			// end-point model
			l += EndPoint(vr, ep);

			Raycast(vr, ep, visitedCellList);
		}
	}

	return l;
}

double SLAMComp::GetLogLikelihood (const VirtualRobot &vr, const std::vector<double> &laserData)
{

	OPRoS::MobilePositionData sensorPos(sensorPosition);
	double c = cos(vr.position.theta);
	double s = sin(vr.position.theta);
	double tmp_x = sensorPos.x * c - sensorPos.y * s;
	double tmp_y = sensorPos.x * s + sensorPos.y * c;
	sensorPos.x = tmp_x + vr.position.x;
	sensorPos.y = tmp_y + vr.position.y;
	sensorPos.theta += vr.position.theta;

	double resolution = (endAngle - startAngle) / (sensorCount - 1);

	double l = 0;
	for (unsigned int i = 0; i < sensorCount; ++i) {
		double v = laserData[i];
		if (minRange <= v && v <= maxRange) {
			OPRoS::MobilePositionData ep (v * cos(sensorPos.theta + startAngle + i * resolution), v * sin(sensorPos.theta + startAngle + i * resolution), sensorPos.theta + startAngle + i * resolution);
			ep.x += sensorPos.x;
			ep.y += sensorPos.y;
			// end-point model
			l += EndPoint(vr, ep);
			//l += -exp(EndPoint(vr, ep));
		}
	}

	return l;
}

void SLAMComp::GetVisitedCellList(const VirtualRobot &vr, const std::vector<double> &laserData, VisitedCellList& visitedCellList)
{
//	std::cout<<"SLAMComp::GetVisitedCellList()"<<std::endl;

	OPRoS::MobilePositionData sensorPos(sensorPosition);
	double c = cos(vr.position.theta);
	double s = sin(vr.position.theta);
	double tmp_x = sensorPos.x * c - sensorPos.y * s;
	double tmp_y = sensorPos.x * s + sensorPos.y * c;
	sensorPos.x = tmp_x + vr.position.x;
	sensorPos.y = tmp_y + vr.position.y;
	sensorPos.theta += vr.position.theta;

	double resolution = (endAngle - startAngle) / (sensorCount - 1);

	for (unsigned int i = 0; i < sensorCount; ++i) {
		double v = laserData[i];
		if (minRange < v && v < maxRange) {
			OPRoS::MobilePositionData ep (v * cos(sensorPos.theta + startAngle + i * resolution), v * sin(sensorPos.theta + startAngle + i * resolution), sensorPos.theta + startAngle + i * resolution);
			ep.x += sensorPos.x;
			ep.y += sensorPos.y;

			Raycast(vr, ep, visitedCellList);
		}
	}
}

double SLAMComp::EndPoint(const VirtualRobot &vr, const OPRoS::MobilePositionData &endPoint)
{
//	std::cout<<"SLAMComp::EndPoint()"<<std::endl;

	OPRoS::MobilePositionData deltaPoint(endPoint.x - vr.position.x, endPoint.y - vr.position.y, 0);
	double distance = sqrt(deltaPoint.x*deltaPoint.x + deltaPoint.y*deltaPoint.y);
	double ratio = ( - sqrt(2)*mapResolution / distance);
	double dx = deltaPoint.x * ratio;
	double dy = deltaPoint.y * ratio;

	OPRoS::MobilePositionData occ_point, free_point;
	double occ_value, free_value;
	double bestSquaredDeltaDistance = searchWindowSize*searchWindowSize * mapResolution*mapResolution / 2.0;
	for (int i=-(int)searchWindowSize/2; i<=(int)searchWindowSize/2; ++i) {
		int h = sqrt(searchWindowSize*searchWindowSize/4.0-i*i);
		for (int j=-h; j<=h; ++j) {
		//for (int j=-(int)searchWindowSize/2; j<=(int)searchWindowSize/2; ++j) {
			occ_point.x = endPoint.x + i * mapResolution;
			occ_point.y = endPoint.y + j * mapResolution;
			free_point.x = occ_point.x + dx;
			free_point.y = occ_point.y + dy;
			if(vr.map->GetCellData(occ_point.x, occ_point.y, occ_value)) {
				vr.map->GetCellData(free_point.x, free_point.y, free_value);
				if (occ_value >= mapLogLikelihoodThreshold && free_value < mapLogLikelihoodThreshold) {
					double hitDistance = sqrt((occ_point.x-vr.position.x)*(occ_point.x-vr.position.x) + (occ_point.y-vr.position.y)*(occ_point.y-vr.position.y));
					bestSquaredDeltaDistance = (bestSquaredDeltaDistance > (hitDistance-distance)*(hitDistance-distance)) ? (hitDistance-distance)*(hitDistance-distance) : bestSquaredDeltaDistance;
				}
			}
		}
	}

	return - bestSquaredDeltaDistance / sensorVariance / 2;
}

void SLAMComp::Raycast (const VirtualRobot &vr, const OPRoS::MobilePositionData &endPoint, VisitedCellList &visitedCellList)
{
//	std::cout<<"SLAMComp::Raycast()"<<std::endl;

	// calculate a list of visited cells
	GridBasedGlobalMap &map = (*vr.map);
	GridBasedGlobalMap::Point minCorner = map.GetMinCorner();

	int p1x = floor((vr.position.x - minCorner[0]) / mapResolution);
	int p1y = floor((vr.position.y - minCorner[1]) / mapResolution);
	int p2x = floor((endPoint.x - minCorner[0]) / mapResolution);
	int p2y = floor((endPoint.y - minCorner[1]) / mapResolution);

	int pdx = p2x - p1x;
	int pdy = p2y - p1y;
	int pcx = p1x;
	int pcy = p1y;

	int dirx = pdx>0 ? 1 : (pdx<0 ? -1 : 0);
	int diry = pdy>0 ? 1 : (pdy<0 ? -1 : 0);

	double dx = vr.position.x - endPoint.x;
	double dy = vr.position.y - endPoint.y;
	double cx = vr.position.x;
	double cy = vr.position.y;

	OPRoS::MobilePositionData currentPoint ((p1x + 0.5)*mapResolution + minCorner[0], (p1y + 0.5)*mapResolution + minCorner[1], 0);

	if (std::abs(pdx) <= std::abs(pdy)) {
		if (diry==0) {
			//visitedCellList.push_back(VisitedCell(currentPoint,(map.GetCellData(currentPoint.x,currentPoint.y,value) && value >= mapLogLikelihoodThreshold)));
			visitedCellList.push_back(VisitedCell(currentPoint, true));
		} else {
			while (diry>0 ? (floor((cy - minCorner[1])/mapResolution) < p2y) : ceil((cy - minCorner[1])/mapResolution)-1 > p2y) {
				double tmp = (cy - minCorner[1])/mapResolution;
				double desx = (((diry>0 ? floor(tmp) : ceil(tmp)) + diry) * mapResolution + minCorner[1] - cy) * dx / dy + cx;
				int pdesx = floor((desx - minCorner[0])/mapResolution);

				while (pcx*dirx < pdesx*dirx) {
					visitedCellList.push_back(VisitedCell(currentPoint, false));

					pcx += dirx;
					currentPoint.x = (pcx + 0.5)*mapResolution + minCorner[0];
				}
				visitedCellList.push_back(VisitedCell(currentPoint, false));

				pcx = pdesx;
				pcy += diry;
				currentPoint.x = (pcx + 0.5)*mapResolution + minCorner[0];
				currentPoint.y = (pcy + 0.5)*mapResolution + minCorner[1];

				cx = desx;
				cy = pcy * mapResolution + minCorner[1];
			}
			while (pcx*dirx < p2x*dirx) {
				visitedCellList.push_back(VisitedCell(currentPoint, false));

				pcx += dirx;
				currentPoint.x = (pcx + 0.5)*mapResolution + minCorner[0];
			}
			visitedCellList.push_back(VisitedCell(currentPoint, true));
		}
	} else {
		if (dirx==0) {
			visitedCellList.push_back(VisitedCell(currentPoint, true));
		} else {
			while (dirx>0 ? (floor((cx - minCorner[0])/mapResolution) < p2x) : ceil((cx - minCorner[0])/mapResolution)-1 > p2x) {
				double tmp = (cx - minCorner[0])/mapResolution;
				double desy = (((dirx>0 ? floor(tmp) : ceil(tmp)) + dirx) * mapResolution + minCorner[0] - cx) * dy / dx + cy;
				int pdesy = floor((desy - minCorner[1])/mapResolution);

				while (pcy*diry < pdesy*diry) {
					visitedCellList.push_back(VisitedCell(currentPoint, false));

					pcy += diry;
					currentPoint.y = (pcy + 0.5)*mapResolution + minCorner[1];
				}
				visitedCellList.push_back(VisitedCell(currentPoint, false));

				pcy = pdesy;
				pcx += dirx;
				currentPoint.x = (pcx + 0.5)*mapResolution + minCorner[0];
				currentPoint.y = (pcy + 0.5)*mapResolution + minCorner[1];

				cy = desy;
				cx = pcx * mapResolution + minCorner[0];
			}
			while (pcy*diry < p2y*diry) {
				visitedCellList.push_back(VisitedCell(currentPoint, false));

				pcy += diry;
				currentPoint.y = (pcy + 0.5)*mapResolution + minCorner[1];
			}
			visitedCellList.push_back(VisitedCell(currentPoint, true));
		}
	}
}

bool SLAMComp::Mapping ()
{
	std::cout<<"SLAMComp::Mapping()"<<std::endl;
	//857~868 주석해제
	// 170911 mskim commant back
	/*
	for (unsigned int i=0; i<particles.size(); ++i) {
		if (!particles[i].map)
			continue;

		GridBasedGlobalMap &map = (*particles[i].map);
		VisitedCellList &visitedCells = visitedCellLists[i];

		map.ClearVisitedCellPtrs();

		for (unsigned int j=0; j<visitedCells.size(); ++j) {
			OPRoS::MobilePositionData &point = visitedCells[j].first;
			map.SetVisitedCellPtrs(point.x, point.y, visitedCells[j].second);
		}
		map.UpdateVisitedCellData();
	}
	*/
	

	std::vector<std::thread> threads(particles.size());
	for (unsigned int i=0; i<particles.size(); ++i) {
		threads[i] = std::thread(&SLAMComp::MappingOne, this, i);
		std::cout << "Hi" << std::endl;
	}
	for (unsigned int i=0; i<particles.size(); ++i) {
		threads[i].join();
		std::cout << "HELLO" << std::endl;
	}
	SelectBestParticle();

#if DEBUG
#if SHOWALL
	for (int i=0; i<NumberOfParticles; ++i) {
		drawmap((*particles[i].map), particles[i].position, i);
	}
#else
	drawmap((*globalMap), currentPosition, 0);
#endif
	cv::waitKey(30);
#endif

	return false;
}

void SLAMComp::MappingOne (unsigned int i)
{

	if (!particles[i].map)
		return;

	GridBasedGlobalMap &map = (*particles[i].map);
	VisitedCellList &visitedCells = visitedCellLists[i];

	map.ClearVisitedCellPtrs();

	for (unsigned int j=0; j<visitedCells.size(); ++j) {
		OPRoS::MobilePositionData &point = visitedCells[j].first;
		map.SetVisitedCellPtrs(point.x, point.y, visitedCells[j].second);
	}
	map.UpdateVisitedCellData();
}

void SLAMComp::SelectBestParticle()
{
	std::cout<<"SLAMComp::SelectBestParticle()"<<std::endl;

	
	unsigned int bestParticleIndex = 0;
	double bestParticleWeight = 10000;//particles[0].weightSum;
	
	
	//std::cout << "no . 0" << particles[0].weightSum << std::endl;
	for (unsigned int i=0; i<particles.size(); ++i) 
	{
		if (particles[i].weightSum < bestParticleWeight) {
			
			bestParticleWeight = particles[i].weightSum;
			bestParticleIndex = i;
		}
			std::cout << " no. "<< i << ' '<< particles[i].weightSum << std::endl;
	}
	

	/*
	unsigned int bestParticleIndex = 0;
	double bestParticleWeight =	particles[0].weight;
	for (unsigned int i=1; i<particles.size(); ++i) {
		if (particles[i].weight > bestParticleWeight) {
			std::cout << "How are you ?" << std::endl;
			bestParticleWeight = particles[i].weight;
			bestParticleIndex = i;
		}
	}*/

	globalMap = particles[bestParticleIndex].map; 
	currentPosition = particles[bestParticleIndex].position;
}

void SLAMComp::ScanMatching(VirtualRobot &vr, const std::vector<double> &laserData)
{
// if performance of the loglikelihood is bad, try score function
// needs to try the scan matching algorithm into Olson's one.
//	std::cout<<"SLAMComp::ScanMatching()"<<std::endl;

	double matchingLinearStepLength = maxMatchingLinearStepLength;
	double matchingAngularStepLength = maxMatchingAngularStepLength;

	VirtualRobot tempVR = vr;
	double tempLogLikelihood = GetLogLikelihood(tempVR, laserData);

	VirtualRobot bestVR = tempVR;
	double bestLogLikelihood = tempLogLikelihood;
	VirtualRobot previousBestVR = bestVR;
	double previousBestLogLikelihood = bestLogLikelihood;
	unsigned int lastTry = 6;

	for (unsigned int i=0; i<matchingFineDegree; ++i) {
		--previousBestLogLikelihood;

		while (previousBestLogLikelihood < bestLogLikelihood) {
			previousBestVR = bestVR;
			previousBestLogLikelihood = bestLogLikelihood;

			for (unsigned int j=0; j<6; ++j) {
				if (j==lastTry) {
					continue;
				}
				double dir = j%2 == 0 ? -1 : 1;

				tempVR = previousBestVR;
				tempVR.position.x += dir * (j/2 == 0 ? matchingLinearStepLength : 0);
				tempVR.position.y += dir * (j/2 == 1 ? matchingLinearStepLength : 0);
				tempVR.position.theta += dir * (j/2 == 2 ? matchingAngularStepLength : 0);
				tempLogLikelihood = GetLogLikelihood(tempVR, laserData);

				if (tempLogLikelihood > bestLogLikelihood) {
					bestVR = tempVR;
					bestLogLikelihood = tempLogLikelihood;
					lastTry = (j/2)*2 + 1 - (j%2);
				}
			}
		}
		matchingLinearStepLength /= 2;
		matchingAngularStepLength /= 2;
	}

	vr = bestVR;
	vr.logLikelihood += bestLogLikelihood;

	/*
	VisitedCellList tempVisitedCellList;
	vr.logLikelihood += GetLogLikelihood(vr, laserData, tempVisitedCellList);
	//*/

	//std::cout<<"estimated loglikelihood = "<<bestLogLikelihood<<std::endl;
}


#if DEBUG
void SLAMComp::line (cv::Mat &im, OPRoS::MobilePositionData p1, OPRoS::MobilePositionData p2, int thick, unsigned char rgb[])
{
	double res = mapResolution;

	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	double cx = p1.x;
	double cy = p1.y;

	int p1x = floor(p1.x/res);
	int p1y = floor(p1.y/res);
	int p2x = floor(p2.x/res);
	int p2y = floor(p2.y/res);
	int pdx = p2x - p1x;
	int pdy = p2y - p1y;
	int pcx = p1x;
	int pcy = p1y;

	int dirx = pdx>0 ? 1 : (pdx<0 ? -1 : 0);
	int diry = pdy>0 ? 1 : (pdy<0 ? -1 : 0);

	if (std::abs(pdx) <= std::abs(pdy)) {
		if (diry==0) {
			mark(im,pcx,pcy,thick,rgb);
		} else {
			while (diry>0 ? (floor(cy/res) < p2y) : ceil(cy/res)-1 > p2y) {
				double desx = (((diry>0 ? floor(cy/res) : ceil(cy/res)) + diry) * res - cy) * dx / dy + cx;
				int pdesx = floor(desx/res);

				while (pcx*dirx < pdesx*dirx) {
					mark(im,pcx,pcy,thick,rgb);
					pcx += dirx;
				}
				mark(im,pcx,pcy,thick,rgb);

				pcx = pdesx;
				pcy += diry;
				cx = desx;
				cy = pcy * res;
			}
			while (pcx*dirx < p2x*dirx) {
				mark(im,pcx,pcy,thick,rgb);
				pcx += dirx;
			}
			mark(im,pcx,pcy,thick,rgb);
		}
	} else {
		if (dirx==0) {
			mark(im,pcx,pcy,thick,rgb);
		} else {
			while (dirx>0 ? (floor(cx/res) < p2x) : ceil(cx/res)-1 > p2x) {
				double desy = (((dirx>0 ? floor(cx/res) : ceil(cx/res)) + dirx) * res - cx) * dy / dx + cy;
				int pdesy = floor(desy/res);

				while (pcy*diry < pdesy*diry) {
					mark(im,pcx,pcy,thick,rgb);
					pcy += diry;
				}
				mark(im,pcx,pcy,thick,rgb);

				pcy = pdesy;
				pcx += dirx;
				cy = desy;
				cx = pcx * res;
			}
			while (pcy*diry < p2y*diry) {
				mark(im,pcx,pcy,thick,rgb);
				pcy += diry;
			}
			mark(im,pcx,pcy,thick,rgb);
		}
	}
}
void SLAMComp::mark (cv::Mat &im, int x, int y, int thick, unsigned char rgb[])
{
	x = x<thick+1 ? thick+1 : (x>im.cols-thick-1 ? im.cols-thick-1 : x);
	y = y<thick+1 ? thick+1 : (y>im.rows-thick-1 ? im.rows-thick-1 : y);

	for (int a=x-thick; a<=x+thick; a++)
		for (int b=y-thick; b<=y+thick; b++) {
			im.at<cv::Vec3b>(b,a)[0] = rgb[2];
			im.at<cv::Vec3b>(b,a)[1] = rgb[1];
			im.at<cv::Vec3b>(b,a)[2] = rgb[0];
		}
}
void SLAMComp::drawmap(GridBasedGlobalMap &map, OPRoS::MobilePositionData position, unsigned int index)
{
	std::vector< std::vector<double> > vecmap;
	double x,y;
	map.GetMap(vecmap,x,y);

	if (vecmap.size()==0) {
		return;
	}

	int nx = vecmap.size();
	int ny = vecmap[0].size();

	int iPositionX = floor((position.x - x)/mapResolution);
	int iPositionY = floor((position.y - y)/mapResolution);

	int dx = 0, dy = 0;
	int addX = 0, addY = 0;
	if (iPositionX >= 0 && iPositionX < nx && iPositionY >= 0 && iPositionY < ny) {
		im = cv::Mat(ny*magnifyingScale, nx*magnifyingScale, CV_8UC3);
	} else {
		if (iPositionX < 0) {
			dx = -iPositionX;
			addX = dx;
		} else if (iPositionX >= nx) {
			dx = 0;
			addX = iPositionX - nx + 1;
		} else {
			dx = 0;
			addX = 0;
		}
		if (iPositionY < 0) {
			dy = -iPositionY;
			addY = dy;
		} else if (iPositionY >= ny) {
			dy = 0;
			addY = iPositionY - ny + 1;
		} else {
			dy = 0;
			addY = 0;
		}

		im = cv::Mat((ny + addY)*magnifyingScale, (nx + addX)*magnifyingScale, CV_8UC3);
	}

	//double threshold = 1 / (1 + exp(-mapLogLikelihoodThreshold));
	for (int i=0; i<nx; ++i) {
		for (int j=0; j<ny; ++j) {
			for (int k=0; k<magnifyingScale; ++k) {
				for (int l=0; l<magnifyingScale; ++l) {
					//im.at<cv::Vec3b>((j+dy)*magnifyingScale+k,(i+dx)*magnifyingScale+l)[0]=im.at<cv::Vec3b>((j+dy)*magnifyingScale+k,(i+dx)*magnifyingScale+l)[1]=im.at<cv::Vec3b>((j+dy)*magnifyingScale+k,(i+dx)*magnifyingScale+l)[2] = 255.0 - 255.0 * (vecmap[i][j] > threshold);
					im.at<cv::Vec3b>((j+dy)*magnifyingScale+k,(i+dx)*magnifyingScale+l)[0]=im.at<cv::Vec3b>((j+dy)*magnifyingScale+k,(i+dx)*magnifyingScale+l)[1]=im.at<cv::Vec3b>((j+dy)*magnifyingScale+k,(i+dx)*magnifyingScale+l)[2] = 255.0 - 255.0 * vecmap[i][j];
				}
			}
		}
	}

	int thick = 1;
	thick *= magnifyingScale;
	int lineThick = thick/2;
	double lineLength = thick*3;
	unsigned char rgb[3] = {255, 0, 0};
	OPRoS::MobilePositionData lastCurrentPosition;
	lastCurrentPosition.x = (iPositionX+dx)*magnifyingScale*mapResolution;
	lastCurrentPosition.y = (iPositionY+dy)*magnifyingScale*mapResolution;
	OPRoS::MobilePositionData endPoint = lastCurrentPosition;
	endPoint.x += lineLength * cos(position.theta) * mapResolution;
	endPoint.y += lineLength * sin(position.theta) * mapResolution;

	std::cout<<"hi1,"<<im.rows<<","<<im.cols<<","<<nx<<","<<ny<<","<<addX<<","<<addY<<","<<dx<<","<<dy<<std::endl;
	line(im,lastCurrentPosition,endPoint,lineThick,rgb);
	mark(im,(iPositionX+dx)*magnifyingScale,(iPositionY+dy)*magnifyingScale,thick,rgb);

	//*
	rgb[0] = 0;
	rgb[1] = rgb[2] = 255;
	OPRoS::MobilePositionData sensorPos(0,0,position.theta);
	double resolution = (endAngle - startAngle) / (sensorCount - 1);
	for (unsigned int i=0; i<lastLaserData.size(); ++i) {
		double v = lastLaserData[i];
		if (minRange < v && v < maxRange) {
			OPRoS::MobilePositionData ep (v * cos(sensorPos.theta + startAngle + i * resolution), v * sin(sensorPos.theta + startAngle + i * resolution), sensorPos.theta + startAngle + i * resolution);
			ep.x += sensorPos.x;
			ep.y += sensorPos.y;
			int iEPX = floor((position.x+ep.x - x)/mapResolution);
			int iEPY = floor((position.y+ep.y - y)/mapResolution);

			for (int k=0; k<magnifyingScale; ++k) {
				for (int l=0; l<magnifyingScale; ++l) {
					if ((iEPY+dy)*magnifyingScale+k < im.rows  && (iEPX+dx)*magnifyingScale+l < im.cols) {
						im.at<cv::Vec3b>((iEPY+dy)*magnifyingScale+k,(iEPX+dx)*magnifyingScale+l)[0] = rgb[2];
						im.at<cv::Vec3b>((iEPY+dy)*magnifyingScale+k,(iEPX+dx)*magnifyingScale+l)[1] = rgb[1];
						im.at<cv::Vec3b>((iEPY+dy)*magnifyingScale+k,(iEPX+dx)*magnifyingScale+l)[2] = rgb[0];
					}
				}
			}
		}
	}
	std::cout<<"hi1,"<<im.rows<<","<<im.cols<<","<<nx<<","<<ny<<","<<addX<<","<<addY<<","<<dx<<","<<dy<<std::endl;
	//*/

	std::stringstream ss;
	ss<<index;

//	cv::imshow("SLAMComp_DEBUG"+ss.str(),im);

	cv::Mat reversedIM;
	cv::flip(im,reversedIM,0);
	cv::imshow("SLAMComp_DEBUG"+ss.str(),reversedIM);
	std::cout<<"hi1,"<<im.rows<<","<<im.cols<<","<<nx<<","<<ny<<","<<addX<<","<<addY<<","<<dx<<","<<dy<<std::endl;
}
#endif

#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
__declspec(dllexport) Component *getComponent();
__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new SLAMComp();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C"
{
	Component *getComponent();
	void releaseComponent(Component *com);
}
Component *getComponent()
{
	return new SLAMComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

