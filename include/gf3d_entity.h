#ifndef __GF3D_ENTITY_H__
#define __GF3D_ENTITY_H__

#include "gf3d_model.h"
#include "gf3d_cube.h"

typedef enum
{
	ES_Idle = 0,
	ES_Dying = 1,
	ES_Dead = 2
}EntityState;

typedef struct
{
	float           boundingX1;
	float           boundingX2;
	float           boundingY1;
	float           boundingY2;
	float           boundingZ1;
	float           boundingZ2;
}BoundingBox;

typedef struct{
	Vector3D planeVert[4];
} Plane;

typedef struct
{
	Plane xy1;
	Plane xy2;
	Plane xz1;
	Plane xz2;
	Plane yz1;
	Plane yz2;
}CubePlane;

typedef struct Entity_S
{
	Uint8           _inuse;         /**<flag to keep track if this isntance is in use and should not be reassigned*/
	Model          *model;          /**<the 3d model for this entity*/
	Vector3D         position;       /**<position of the entity in 3d space*/
	Vector3D         velocity;       /**<velocity of the entity in 3d space*/
	Vector3D         acceleration;   /**<acceleration of the entity in 3d space*/
	Vector3D         rotation;       /**<yaw, pitch, and roll of the entity*/
	Vector3D         scale;          /**<*please default to 1,1,1*/
	EntityState     state;          /**<current state of the entity*/
	void (*think)(struct Entity_S* self);   /**<function called on entity think*/
	void (*update)(struct Entity_S* self);   /**<function called on entity update*/
	void (*touch)(struct Entity_S* self, struct Entity_S* other);   /**<function called on entity think*/
	float           health;
	float           healthmax;
	float           armor;
	float			accelLeft;		/*Acceleration to the left is handled here.*/
	float			accelRight;		/*Acceleration to the right is handled here.*/
	float			accelForward;   /*Acceleration forward*/
	float			brakeModd;		/*Brake on car. in other words deccel on car.*/
	float			grip;			/*Grip on car tire*/
	float			handling;		/*handling on turn*/
	float			maxspeed;		/*Max speed on car*/
	int				carNum;			/*The car selected*/
	float			accel;
	int				guntype;
	BoundingBox     entityBoundingBoxes;
	Matrix4         *entityMat;
	Bool            isEnvironment;
	Bool            isEnvironment2;
	int				mass;
	float           width;
	float           depth;
	float           height;
	char            *name;
	float           lastUpdate;
	Vector3D		lastVel;
	float			otherstuff;
	CubePlane		cp;
	int				numAnimations;
	box				box; // Box creation code
	float			poweruptime;
	float			poweruppickup;
	void *data;                     /**<additional entity specific data*/

}Entity;

/**
* @brief initializes the entity subsystem
* @param entity_max maximum number of simultaneous entities you wish to support
*/
void gf3d_entity_manager_init(Uint32 entity_max);

/**
* @brief get an empty entity from the system
* @return NULL on out of space or a pointer to an entity otherwise
*/
Entity *gf3d_entity_new();

/**
* @brief free an active entity
* @param self the entity to free
*/
void    gf3d_entity_free(Entity *self);
void gf3d_update_all_entities();
void update_entity(Entity *e);
void gf3d_entity_sync_position(Entity *e);
void gf3d_set_entity_bounding_box(Entity *e);
Entity * gf3d_entity_init(char * model, Bool isEnvironment, int startFrame, int endFrame);
void gf3d_entity_move(Entity * e, float x, float y, float z);
void gf3d_entity_draw(Entity * e, int frame, Uint32 bufferFrame, VkCommandBuffer commandBuffer);
int gf3d_entity_manager_get_size();
Entity * gf3d_entity_manager_get_entity(int n);

void gf3d_entity_setup_cube_plane(Entity * e);
#endif