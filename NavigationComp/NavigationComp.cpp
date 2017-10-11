/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "NavigationComp.h"

//
// constructor declaration
//
NavigationComp::NavigationComp() {
	ptrObstacleAvoidanceService = NULL;

	ptrPathPlanningService = NULL;

	ptrSLAMService = NULL;

	portSetup();
}

//
// constructor declaration (with name)
//
NavigationComp::NavigationComp(const std::string &name) :
		Component(name) {
	ptrObstacleAvoidanceService = NULL;

	ptrPathPlanningService = NULL;

	ptrSLAMService = NULL;

	portSetup();
}

//
// destructor declaration
//

NavigationComp::~NavigationComp() {
}
std::vector<std::vector<bool> > NavigationComp::GetBinaryMap() {
	//user code hear
	double rad = 1 * robotRadius / mapResolution;

	std::vector<std::vector<std::pair<bool, double> > > tempMap(
			currentMap.size(),
			std::vector<std::pair<bool, double> >(currentMap[0].size(),
					std::pair<bool, double>(false,
							(std::numeric_limits<double>::max)())));
	for (int j = 0; j < (int) currentMap[0].size(); ++j) {
		int lastX = -1;
		for (int i = 0; i < (int) currentMap.size(); ++i) {
			if (currentMap[i][j] > mapOccProbThreshold) {
				int x = ((lastX - rad + i) / 2.0 > i - rad) ?
						ceil((lastX - rad + i) / 2.0) : i - rad;
				for (int k = (x >= 0 ? x : 0);
						k
								< (i + rad + 1 <= (int) currentMap.size() ?
										i + rad + 1 : (int) currentMap.size());
						++k) {
					tempMap[k][j].first = true;
					tempMap[k][j].second =
							(abs(k - i) < tempMap[k][j].second) ?
									abs(k - i) : tempMap[k][j].second;
				}
				lastX = i + rad;
			}
			if (lastX + 1 >= (int) currentMap.size()) {
				break;
			}
		}
	}

	std::vector<std::vector<bool> > binaryMap(currentMap.size(),
			std::vector<bool>(currentMap[0].size(), false));
	for (int i = 0; i < (int) tempMap.size(); ++i) {
		int lastY1 = -rad - 1;
		int lastY2 = -rad - 1;
		for (int j = 0; j < (int) tempMap[0].size(); ++j) {
			if (tempMap[i][j].first) {
				int h = sqrt(
						rad * rad
								- tempMap[i][j].second * tempMap[i][j].second);

				int y1;
				int y2;

				if (j - h < lastY1 && j + h <= lastY2) {
					y1 = j - h;
					y2 = lastY1 - 1;
					lastY1 = y1;
				} else if (j - h < lastY1 && j + h > lastY2) {
					y1 = j - h;
					y2 = j + h;
					lastY1 = y1;
					lastY2 = y2;
				} else if (j - h >= lastY1 && j - h <= lastY2
						&& j + h > lastY2) {
					y1 = lastY2 + 1;
					y2 = j + h;
					lastY2 = y2;
				} else if (j - h > lastY2) {
					y1 = j - h;
					y2 = j + h;
					lastY1 = y1;
					lastY2 = y2;
				} else {
					y1 = j;
					y2 = j;
				}

				for (int k = (y1 >= 0 ? y1 : 0);
						k
								<= (y2 < (int) tempMap[0].size() ?
										y2 : (int) tempMap[0].size() - 1);
						++k) {
					binaryMap[i][k] = true;
				}
			}
		}
	}

	return binaryMap;
}

double NavigationComp::GetMapHeight() {
	//user code hear
	return mapHeight;
}

double NavigationComp::GetMapWidth() {
	//user code hear
	return mapWidth;
}

double NavigationComp::GetMapStartY() {
	//user code hear
	return mapStartY;
}

double NavigationComp::GetMapStartX() {
	//user code hear
	return mapStartX;
}

double NavigationComp::GetMapCellSize() {
	//user code hear
	return mapResolution;
}

void NavigationComp::portSetup() {
//data port setup
	addPort("velocity", &velocity);

//data port setup
	/*addPort("velocity", &velocity);*/

//data port setup
	/*addPort("velocity", &velocity);*/

	ptrObstacleAvoidanceService = new ObstacleAvoidanceServiceRequired();
	addPort("ObstacleAvoidanceService", ptrObstacleAvoidanceService);

	ProvidedServicePort *pa1;
	pa1 = new GlobalMapServiceProvided(this);
	addPort("GlobalMapService", pa1);

	ptrPathPlanningService = new PathPlanningServiceRequired();
	addPort("PathPlanningService", ptrPathPlanningService);

//data port setup
	/*addPort("velocity", &velocity);*/

	ptrSLAMService = new SLAMServiceRequired();
	addPort("SLAMService", ptrSLAMService);

	// export variable setup

}

// Call back Declaration
ReturnType NavigationComp::onInitialize() {
	// user code here
	stepVelocity.x = 0.05;
	stepVelocity.theta = DEG2RAD(10);
	useTargetPosition = false;
	isLButtonDragging = false;
	addTarget = false;
	robotRadius = 0.2;
	safeMode = true;

	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onStart() {
	// user code here
	magnifyingScale = 5;

	//ptrSLAMService->LoadMapFile("saveMap");

//	mapOccProbThreshold = atof(ptrSLAMService->GetParameter().GetValue("MapOccProbThreshold").c_str());
	mapOccProbThreshold =
			atof(
					ptrSLAMService->GetProperty().GetValue(
							"MapOccProbThreshold").c_str());

	mapOccProbThreshold = safeMode ? 0.3 : mapOccProbThreshold;

	std::thread t(&NavigationComp::ProcessGUI, this);
	t.detach();
	ctrlPressed = false;
	showConfigSpace = false;

	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onStop() {
	// user code here
	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onReset() {
	// user code here
	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onError() {
	// user code here
	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onRecover() {
	// user code here
	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onDestroy() {
	// user code here
	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onEvent(Event *evt) {
	// user code here
	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onExecute() {
	// user code here

	if (useTargetPosition) {
		CalculateVelocity();
	} else {
		if (targetPositionSet.size() > 0) {
//			std::cout<<targetPositionSet.size<<std::endl;
			targetPositionSet.clear();
		}
	}

	if (previousVelocity.x != currentVelocity.x
			|| previousVelocity.theta != currentVelocity.theta) {
		velocity.push(currentVelocity);
		previousVelocity = currentVelocity;
	}

	/*
	currentVelocity.x=10.0;
	currentVelocity.y=10.0;
	currentVelocity.theta=1.0;
	velocity.push(currentVelocity);	*///170910 상규추가 mobilecomp에 dataport로 velocity값 push

	auto temp = ptrSLAMService->GetMap();
	if (temp.empty())
	{
		return OPROS_SUCCESS;
	}
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
			std::cout << temp[i][j] << ' ';
		std::cout << "\n";
	}
	currentMap.swap(temp);
	mapStartX = ptrSLAMService->GetMapStartX();
	mapStartY = ptrSLAMService->GetMapStartY();
	mapWidth = ptrSLAMService->GetMapWidth();
	mapHeight = ptrSLAMService->GetMapHeight();
	//mapHeight = ptrSLAMService->GetMapWidth(); 170910
	currentPosition = ptrSLAMService->GetPosition();
	mapResolution = ptrSLAMService->GetMapCellSize();


	//ptrSLAMService->SaveMapFile("saveMap");

	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onUpdated() {
	// user code here
	return OPROS_SUCCESS;
}

ReturnType NavigationComp::onPeriodChanged() {
	// user code here
	return OPROS_SUCCESS;
}

void NavigationComp::CalculateVelocity() {
	double remainDistance = sqrt(
			pow(currentSubTargetPosition.x - currentPosition.x, 2.0)
					+ pow(currentSubTargetPosition.y - currentPosition.y, 2.0));
	double remainAngularDistance = atan2(
			currentSubTargetPosition.y - currentPosition.y,
			currentSubTargetPosition.x - currentPosition.x)
			- currentPosition.theta;
	remainAngularDistance -= ceil(
			remainAngularDistance / 2 / M_PI - 0.5)*2*M_PI;
	double remainFinalAngularDistance = currentSubTargetPosition.theta
			- currentPosition.theta;
	remainFinalAngularDistance -= ceil(
			remainFinalAngularDistance / 2 / M_PI - 0.5) * 2 * M_PI;

	switch (navigationStep) {
	case NS_IDLE:
		break;
	case NS_NAVIGATION_TO: {
		OPRoS::MobileVelocityData vel = ptrObstacleAvoidanceService->Avoid(
				currentPosition, currentSubTargetPosition);
		currentVelocity.x = vel.x;
		if (vel.theta > 6 * stepVelocity.theta) {
			currentVelocity.x = 0;
			currentVelocity.theta = 2 * stepVelocity.theta;
		} else if (vel.theta > 4 * stepVelocity.theta) {
			currentVelocity.theta = 1.5 * stepVelocity.theta;
		} else if (vel.theta > 1. * stepVelocity.theta) {
			currentVelocity.theta = 1 * stepVelocity.theta;
		} else if (vel.theta < -6 * stepVelocity.theta) {
			currentVelocity.x = 0;
			currentVelocity.theta = -2 * stepVelocity.theta;
		} else if (vel.theta < -4 * stepVelocity.theta) {
			currentVelocity.theta = -1.5 * stepVelocity.theta;
		} else if (vel.theta < -1. * stepVelocity.theta) {
			currentVelocity.theta = -1 * stepVelocity.theta;
		} else {
			double SpeedFactor;
			if (remainDistance > 20 * mapResolution) {
				SpeedFactor = 3;
			} else if (remainDistance > 10 * mapResolution) {
				SpeedFactor = 2;
			} else {
				SpeedFactor = 1;
			}
			currentVelocity.x = SpeedFactor * vel.x;
			currentVelocity.theta = 0;

			if (remainDistance < 5 * mapResolution) {
				if (currentPath.size() > 0) {
					currentSubTargetPosition = currentPath[0];
					currentPath.erase(currentPath.begin());
				} else {
					if (targetPositionSet.size() > 0) {
						currentTargetPosition = targetPositionSet[0];
						targetPositionSet.erase(targetPositionSet.begin());

						currentPath = ptrPathPlanningService->FindPath(
								currentPosition, currentTargetPosition);
						if (currentPath.size() == 0) {
							currentSubTargetPosition = currentTargetPosition;
						} else {
							currentSubTargetPosition = currentPath[0];
							currentPath.erase(currentPath.begin());
						}
					} else {
						navigationStep = NS_TURN;
					}
				}
			}
		}
	
		break;
	}

	case NS_TURN: {
		currentVelocity.x = 0;
		if (remainFinalAngularDistance > DEG2RAD(90)) {
			currentVelocity.theta = 2 * stepVelocity.theta;
		} else if (remainFinalAngularDistance > DEG2RAD(45)) {
			currentVelocity.theta = 1.5 * stepVelocity.theta;
		} else if (remainFinalAngularDistance > DEG2RAD(0)) {
			currentVelocity.theta = 1 * stepVelocity.theta;
		} else if (remainFinalAngularDistance < -DEG2RAD(60)) {
			currentVelocity.theta = -2 * stepVelocity.theta;
		} else if (remainFinalAngularDistance < -DEG2RAD(45)) {
			currentVelocity.theta = -1.5 * stepVelocity.theta;
		} else if (remainFinalAngularDistance < -DEG2RAD(0)) {
			currentVelocity.theta = -1 * stepVelocity.theta;
		}

		/*
		 if(remainFinalAngularDistance > 0) {
		 currentVelocity.theta = autoVelocity.theta/6;
		 } else if(remainFinalAngularDistance < 0) {
		 currentVelocity.theta = -autoVelocity.theta/6;
		 }
		 //*/

		if (RAD2DEG(fabs(remainFinalAngularDistance)) < 5.) {
			navigationStep = NS_STOP;
		}

		break;
	}

	case NS_STOP:
		currentVelocity.x = currentVelocity.theta = 0;
		navigationStep = NS_IDLE;
		useTargetPosition = false;
		break;
	default:
		break;
	}
}

void NavigationComp::ProcessGUI() {
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *eventbox;
	GtkWidget *darea;
	GtkWidget *button;
	GtkWidget *frame;

	gtk_init(0, nullptr);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "KITECH_SLAM");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_window_set_default_size(GTK_WINDOW(window), 1000, 800);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	frame = gtk_frame_new("Estimated map");
	gtk_grid_attach(GTK_GRID(grid), frame, 0, 0, 3, 1);

	eventbox = gtk_event_box_new();
	gtk_widget_set_hexpand(eventbox, TRUE);
	gtk_widget_set_halign(eventbox, GTK_ALIGN_CENTER);
	gtk_widget_set_vexpand(eventbox, TRUE);
	gtk_widget_set_valign(eventbox, GTK_ALIGN_CENTER);
	gtk_widget_set_size_request(eventbox, 800, 800);
	gtk_container_set_border_width(GTK_CONTAINER(eventbox), 10);
	gtk_container_add(GTK_CONTAINER(frame), eventbox);

	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(eventbox), darea);

	g_signal_connect(G_OBJECT(eventbox), "motion_notify_event",
			G_CALLBACK(NavigationComp::OnMouseDrag), (gpointer )this);
	g_signal_connect(G_OBJECT(eventbox), "button_press_event",
			G_CALLBACK(NavigationComp::OnMousePress), (gpointer )this);
	g_signal_connect(G_OBJECT(eventbox), "button_release_event",
			G_CALLBACK(NavigationComp::OnMouseRelease), (gpointer )this);
	g_signal_connect(G_OBJECT(darea), "draw",
			G_CALLBACK(NavigationComp::OnDraw), (gpointer )this);

	button = gtk_button_new_with_label("Save map");
	gtk_widget_set_can_focus(button, FALSE);
	gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

	g_signal_connect(G_OBJECT(button), "clicked",
			G_CALLBACK(NavigationComp::OnButtonClick), (gpointer )this);

	button = gtk_button_new_with_label("Load map");
	gtk_widget_set_can_focus(button, FALSE);
	gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);
	g_signal_connect(G_OBJECT(button), "clicked",
			G_CALLBACK(NavigationComp::OnButtonClick), (gpointer )this);

	button = gtk_button_new_with_label("Restart SLAM");
	gtk_widget_set_can_focus(button, FALSE);
	gtk_grid_attach(GTK_GRID(grid), button, 2, 1, 1, 1);
	g_signal_connect(G_OBJECT(button), "clicked",
			G_CALLBACK(NavigationComp::OnButtonClick), (gpointer )this);

	g_signal_connect(G_OBJECT(window), "key_press_event",
			G_CALLBACK(NavigationComp::OnKeyPress), (gpointer )this);
	g_signal_connect(G_OBJECT(window), "key_release_event",
			G_CALLBACK(NavigationComp::OnKeyRelease), (gpointer )this);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit),
			nullptr);

	gtk_widget_show_all(window);

	g_timeout_add(100, (GSourceFunc) NavigationComp::Redraw, (gpointer) darea);

	gtk_main();
}

gboolean NavigationComp::OnKeyPress(GtkWindow *window, GdkEventKey *event,
		gpointer data) {
	NavigationComp &component = *(NavigationComp *) data;

	if (event->keyval == GDK_KEY_Control_L) {
		component.ctrlPressed = true;
	} else if (event->keyval == GDK_KEY_Up || event->keyval == GDK_KEY_Down
			|| event->keyval == GDK_KEY_Left || event->keyval == GDK_KEY_Right
			|| event->keyval == GDK_KEY_s || event->keyval == GDK_KEY_S) {
		component.ClearAutoNaviInfo();

		switch (event->keyval) {
		case GDK_KEY_Up:
			component.currentVelocity.x += component.stepVelocity.x;
			

			component.currentPosition.x++;
			component.currentPosition.y++;
			component.currentPosition.theta++;
			//09-13 상규추가
			
			break;
		case GDK_KEY_Down:
			component.currentVelocity.x -= component.stepVelocity.x;
			break;

		case GDK_KEY_Left:
			component.currentVelocity.theta += 5;
			break;
		case GDK_KEY_Right:
			component.currentVelocity.theta -= 5;
			break;

//		case GDK_KEY_Left:
//			component.currentVelocity.theta += component.stepVelocity.theta;
//			break;
//		case GDK_KEY_Right:
//			component.currentVelocity.theta -= component.stepVelocity.theta;
//			break;
		case GDK_KEY_S:
			component.currentVelocity.x = component.currentVelocity.theta = 0;
			break;
		case GDK_KEY_s:
			component.currentVelocity.x = component.currentVelocity.theta = 0;
			break;
		default:
			break;
		}
	} else {
		if (event->keyval == GDK_KEY_c) {
			component.showConfigSpace = !component.showConfigSpace;
		}
	}

	return FALSE;
}

gboolean NavigationComp::OnKeyRelease(GtkWindow *window, GdkEventKey *event,
		gpointer data) {
	NavigationComp &component = *(NavigationComp *) data;

	component.ctrlPressed =
			(event->keyval == GDK_KEY_Control_L) ?
					false : component.ctrlPressed;

	return FALSE;
}

gboolean NavigationComp::OnMousePress(GtkWindow *window, GdkEventButton *event,
		gpointer data) {
	NavigationComp &component = *(NavigationComp *) data;

	if (event->button != 1) {
		return FALSE;
	}

	component.isLButtonDragging = true;
	component.useTargetPosition = true;
	component.addTarget = component.ctrlPressed;

	component.targetPosition.x = (event->x / component.magnifyingScale
			- component.mapImageOffsetX) * component.mapResolution
			+ component.mapStartX;
	component.targetPosition.y = ((component.mapImageHeight
			* component.magnifyingScale - 1 - event->y)
			/ component.magnifyingScale - component.mapImageOffsetY)
			* component.mapResolution + component.mapStartY;

	return FALSE;
}

gboolean NavigationComp::OnMouseDrag(GtkWindow *window, GdkEventMotion *event,
		gpointer data) {
	NavigationComp &component = *(NavigationComp *) data;

	double cX = (event->x / component.magnifyingScale
			- component.mapImageOffsetX) * component.mapResolution
			+ component.mapStartX;
	double cY = ((component.mapImageHeight * component.magnifyingScale - 1
			- event->y) / component.magnifyingScale - component.mapImageOffsetY)
			* component.mapResolution + component.mapStartY;
	component.targetPosition.theta = atan2(cY - component.targetPosition.y,
			cX - component.targetPosition.x);

	return FALSE;
}

gboolean NavigationComp::OnMouseRelease(GtkWindow *window,
		GdkEventButton *event, gpointer data) {
	NavigationComp &component = *(NavigationComp *) data;

	if (event->button != 1) {
		return FALSE;
	}

	double cX = (event->x / component.magnifyingScale
			- component.mapImageOffsetX) * component.mapResolution
			+ component.mapStartX;
	double cY = ((component.mapImageHeight * component.magnifyingScale - 1
			- event->y) / component.magnifyingScale - component.mapImageOffsetY)
			* component.mapResolution + component.mapStartY;
	component.targetPosition.theta = atan2(cY - component.targetPosition.y,
			cX - component.targetPosition.x);

	component.isLButtonDragging = false;

	if (component.navigationStep == NS_NAVIGATION_TO && component.addTarget) {
		component.targetPositionSet.push_back(component.targetPosition);
	} else {
		component.targetPositionSet.clear();
		component.currentTargetPosition = component.targetPosition;
		component.currentPath = component.ptrPathPlanningService->FindPath(
				component.currentPosition, component.currentTargetPosition);
		if (component.currentPath.size() == 0) {
			component.currentSubTargetPosition =
					component.currentTargetPosition;
		} else {
			component.currentSubTargetPosition = component.currentPath[0];
			component.currentPath.erase(component.currentPath.begin());
		}
	}
	component.navigationStep = NS_NAVIGATION_TO;

	return FALSE;
}

gboolean NavigationComp::OnDraw(GtkWindow *window, cairo_t *cr, gpointer data) {
	NavigationComp &component = *(NavigationComp *) data;

	const std::vector<std::vector<double> > &vecmap = component.currentMap;
	double x = component.mapStartX;
	double y = component.mapStartY;
	const OPRoS::MobilePositionData position = component.currentPosition;
	double mapResolution = component.mapResolution;

	if (vecmap.size() == 0) {
		return FALSE;
	}

	int nx = vecmap.size();
	int ny = vecmap[0].size();

	int iPositionX = floor((position.x - x) / mapResolution);
	int iPositionY = floor((position.y - y) / mapResolution);

	int dx = 0, dy = 0;
	int addX = 0, addY = 0;
	if (iPositionX >= 0 && iPositionX < nx && iPositionY >= 0
			&& iPositionY < ny) {

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
	}

	component.mapImageWidth = nx + addX;
	component.mapImageHeight = ny + addY;
	component.mapImageOffsetX = dx;
	component.mapImageOffsetY = dy;

	double areasize = 800;
	double widthRatio = areasize / component.mapImageWidth;
	double heightRatio = areasize / component.mapImageHeight;
	double scale = (std::min)(
			(std::min)(widthRatio, heightRatio), component.magnifyingScale);
	component.magnifyingScale = scale;

	cairo_scale(cr, component.magnifyingScale, component.magnifyingScale);
	cairo_set_line_width(cr, 0);

	GdkPixbuf *pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8,
			component.mapImageWidth, component.mapImageHeight);
	int rowstride, n_channels;
	guchar *pixels, *p;
	n_channels = gdk_pixbuf_get_n_channels(pixbuf);
	rowstride = gdk_pixbuf_get_rowstride(pixbuf);
	pixels = gdk_pixbuf_get_pixels(pixbuf);

	std::vector<std::vector<bool> > vecmap_cfs;
	if (component.showConfigSpace) {
		vecmap_cfs = component.GetBinaryMap();
	}

	for (int i = 0; i < nx; ++i) {
		for (int j = 0; j < ny; ++j) {
			p = pixels
					+ (component.mapImageHeight - 1
							- (j + component.mapImageOffsetY)) * rowstride
					+ (i + component.mapImageOffsetX) * n_channels;

			if (component.showConfigSpace && !vecmap_cfs.empty())
			{
				p[0] = p[1] = p[2] = (255 - 255.0 * vecmap_cfs[i][j]);
			}
			else if (!vecmap.empty() && !vecmap[i].empty())
			{
				p[0] = p[1] = p[2] = (255 - 255.0 * vecmap[i][j]);
			}
		}
	}

	gdk_cairo_set_source_pixbuf(cr, pixbuf, 0.0, 0.0);
	cairo_paint(cr);
	g_object_unref(pixbuf);

	double thick = 1;
	double lineThick = thick / 2;
	double lineLength = thick * 3;

	cairo_set_source_rgb(cr, 1, 0, 0);
	cairo_arc(cr, iPositionX + component.mapImageOffsetX,
			component.mapImageHeight - 1
					- (iPositionY + component.mapImageOffsetY), thick, 0,
			2 * M_PI);
	cairo_fill(cr);
	cairo_set_line_width(cr, lineThick);
	cairo_move_to(cr, iPositionX + component.mapImageOffsetX,
			component.mapImageHeight - 1
					- (iPositionY + component.mapImageOffsetY));
	cairo_rel_line_to(cr, lineLength * cos(position.theta),
			-lineLength * sin(position.theta));
	cairo_stroke(cr);
	cairo_set_line_width(cr, 0);

	if (component.useTargetPosition) {
		if (component.isLButtonDragging) {
			cairo_set_source_rgb(cr, 0, component.addTarget ? 0 : 1,
					component.addTarget ? 1 : 0);
			cairo_arc(cr,
					floor((component.targetPosition.x - x) / mapResolution)
							+ component.mapImageOffsetX,
					component.mapImageHeight - 1
							- (floor(
									(component.targetPosition.y - y)
											/ mapResolution)
									+ component.mapImageOffsetY), thick, 0,
					2 * M_PI);
			cairo_fill(cr);
			cairo_set_line_width(cr, lineThick);
			cairo_move_to(cr,
					floor((component.targetPosition.x - x) / mapResolution)
							+ component.mapImageOffsetX,
					component.mapImageHeight - 1
							- (floor(
									(component.targetPosition.y - y)
											/ mapResolution)
									+ component.mapImageOffsetY));
			cairo_rel_line_to(cr,
					lineLength * cos(component.targetPosition.theta),
					-lineLength * sin(component.targetPosition.theta));
			cairo_stroke(cr);
			cairo_set_line_width(cr, 0);
		}

		if (!component.isLButtonDragging
				|| (component.isLButtonDragging && component.addTarget
						&& component.navigationStep == NS_NAVIGATION_TO)) {
			cairo_set_source_rgb(cr, 0, 1, 0);
			cairo_arc(cr,
					floor(
							(component.currentTargetPosition.x - x)
									/ mapResolution)
							+ component.mapImageOffsetX,
					component.mapImageHeight - 1
							- (floor(
									(component.currentTargetPosition.y - y)
											/ mapResolution)
									+ component.mapImageOffsetY), thick, 0,
					2 * M_PI);
			cairo_fill(cr);
			cairo_set_line_width(cr, lineThick);
			cairo_move_to(cr,
					floor(
							(component.currentTargetPosition.x - x)
									/ mapResolution)
							+ component.mapImageOffsetX,
					component.mapImageHeight - 1
							- (floor(
									(component.currentTargetPosition.y - y)
											/ mapResolution)
									+ component.mapImageOffsetY));
			cairo_rel_line_to(cr,
					lineLength * cos(component.currentTargetPosition.theta),
					-lineLength * sin(component.currentTargetPosition.theta));
			cairo_stroke(cr);
			cairo_set_line_width(cr, 0);
		}

		cairo_set_source_rgb(cr, 0, 0, 1);
		for (unsigned int i = 0; i < component.targetPositionSet.size(); ++i) {
			cairo_arc(cr,
					floor(
							(component.targetPositionSet[i].x - x)
									/ mapResolution)
							+ component.mapImageOffsetX,
					component.mapImageHeight - 1
							- (floor(
									(component.targetPositionSet[i].y - y)
											/ mapResolution)
									+ component.mapImageOffsetY), thick, 0,
					2 * M_PI);
			cairo_fill(cr);
			cairo_set_line_width(cr, lineThick);
			cairo_move_to(cr,
					floor(
							(component.targetPositionSet[i].x - x)
									/ mapResolution)
							+ component.mapImageOffsetX,
					component.mapImageHeight - 1
							- (floor(
									(component.targetPositionSet[i].y - y)
											/ mapResolution)
									+ component.mapImageOffsetY));
			cairo_rel_line_to(cr,
					lineLength * cos(component.targetPositionSet[i].theta),
					-lineLength * sin(component.targetPositionSet[i].theta));
			cairo_stroke(cr);

			cairo_set_line_width(cr, lineThick / 2);
			if (i > 0) {
				cairo_move_to(cr,
						floor(
								(component.targetPositionSet[i - 1].x - x)
										/ mapResolution)
								+ component.mapImageOffsetX,
						component.mapImageHeight - 1
								- (floor(
										(component.targetPositionSet[i - 1].y
												- y) / mapResolution)
										+ component.mapImageOffsetY));
				cairo_line_to(cr,
						floor(
								(component.targetPositionSet[i].x - x)
										/ mapResolution)
								+ component.mapImageOffsetX,
						component.mapImageHeight - 1
								- (floor(
										(component.targetPositionSet[i].y - y)
												/ mapResolution)
										+ component.mapImageOffsetY));
			} else {
				cairo_move_to(cr,
						floor(
								(component.currentTargetPosition.x - x)
										/ mapResolution)
								+ component.mapImageOffsetX,
						component.mapImageHeight - 1
								- (floor(
										(component.currentTargetPosition.y - y)
												/ mapResolution)
										+ component.mapImageOffsetY));
				cairo_line_to(cr,
						floor(
								(component.targetPositionSet[i].x - x)
										/ mapResolution)
								+ component.mapImageOffsetX,
						component.mapImageHeight - 1
								- (floor(
										(component.targetPositionSet[i].y - y)
												/ mapResolution)
										+ component.mapImageOffsetY));
			}
			cairo_stroke(cr);
			cairo_set_line_width(cr, 0);
		}

		cairo_set_source_rgb(cr, 0, 1, 1);
		for (unsigned int i = 0; i < component.currentPath.size(); ++i) {
			cairo_arc(cr,
					floor((component.currentPath[i].x - x) / mapResolution)
							+ component.mapImageOffsetX,
					component.mapImageHeight - 1
							- (floor(
									(component.currentPath[i].y - y)
											/ mapResolution)
									+ component.mapImageOffsetY), thick, 0,
					2 * M_PI);
			cairo_fill(cr);

			cairo_set_line_width(cr, lineThick / 2);
			if (i > 0) {
				cairo_move_to(cr,
						floor(
								(component.currentPath[i - 1].x - x)
										/ mapResolution)
								+ component.mapImageOffsetX,
						component.mapImageHeight - 1
								- (floor(
										(component.currentPath[i - 1].y - y)
												/ mapResolution)
										+ component.mapImageOffsetY));
				cairo_line_to(cr,
						floor((component.currentPath[i].x - x) / mapResolution)
								+ component.mapImageOffsetX,
						component.mapImageHeight - 1
								- (floor(
										(component.currentPath[i].y - y)
												/ mapResolution)
										+ component.mapImageOffsetY));
			} else {
				cairo_move_to(cr,
						floor(
								(component.currentSubTargetPosition.x - x)
										/ mapResolution)
								+ component.mapImageOffsetX,
						component.mapImageHeight - 1
								- (floor(
										(component.currentSubTargetPosition.y
												- y) / mapResolution)
										+ component.mapImageOffsetY));
				cairo_line_to(cr,
						floor((component.currentPath[i].x - x) / mapResolution)
								+ component.mapImageOffsetX,
						component.mapImageHeight - 1
								- (floor(
										(component.currentPath[i].y - y)
												/ mapResolution)
										+ component.mapImageOffsetY));
			}
			cairo_stroke(cr);
			cairo_set_line_width(cr, 0);
		}

		if (component.navigationStep != NS_IDLE) {
			cairo_set_line_width(cr, lineThick / 2);
			cairo_move_to(cr,
					floor((component.currentPosition.x - x) / mapResolution)
							+ component.mapImageOffsetX,
					component.mapImageHeight - 1
							- (floor(
									(component.currentPosition.y - y)
											/ mapResolution)
									+ component.mapImageOffsetY));
			cairo_line_to(cr,
					floor(
							(component.currentSubTargetPosition.x - x)
									/ mapResolution)
							+ component.mapImageOffsetX,
					component.mapImageHeight - 1
							- (floor(
									(component.currentSubTargetPosition.y - y)
											/ mapResolution)
									+ component.mapImageOffsetY));
			cairo_stroke(cr);
			cairo_set_line_width(cr, 0);
		}
	}

	return FALSE;
}

gboolean NavigationComp::Redraw(gpointer data) {
	gtk_widget_queue_draw((GtkWidget *) data);

	return TRUE;
}

gboolean NavigationComp::OnButtonClick(GtkButton *button, gpointer data) {
	NavigationComp &component = *static_cast<NavigationComp *>(data);
	const gchar *label = gtk_button_get_label(button);

	if (strcmp(label, "Save map") == 0) {
		component.ClearAutoNaviInfo();
		component.ptrSLAMService->SaveMapFile("map");
	} else if (strcmp(label, "Load map") == 0) {
		component.ClearAutoNaviInfo();
		component.ptrSLAMService->LoadMapFile("map");
	} else if (strcmp(label, "Restart SLAM") == 0) {
		component.ClearAutoNaviInfo();
		component.ptrSLAMService->ReStartSLAM();
	}

	return FALSE;
}

void NavigationComp::ClearAutoNaviInfo() {
	useTargetPosition = false;
	targetPositionSet.clear();
	currentPath.clear();
	addTarget = false;
	navigationStep = NS_IDLE;
}

#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
	__declspec(dllexport) Component *getComponent();
	__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new NavigationComp();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C" {
Component *getComponent();
void releaseComponent(Component *com);
}
Component *getComponent() {
	return new NavigationComp();
}

void releaseComponent(Component *com) {
	delete com;
}
#endif
#endif

