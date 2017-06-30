#ifndef MIROBOT
#define MIROBOT
#include "listner.h"
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
namespace gazebo{
   struct Union{
	   physics::JointPtr joint;
	   common::PID pid;
	   common::Time tiempoActual;

	   double velocidad;
	   double anguloFinal;

	   bool moviendo=false;

   };
    class Listner;
	class MiRobot: public ModelPlugin{
		Listner *listner;
		physics::ModelPtr modelo;
		sdf::ElementPtr sdf;
		std::map<std::string,Union> uniones;
		event::ConnectionPtr conexionUpdate;

		std::string estado;
		std::map<std::string,physics::BasePtr> buscar(physics::BasePtr contenedor, const physics::Entity::EntityType &);
		public:
		void Load (physics::ModelPtr _model,sdf::ElementPtr _sdf);
		void OnUpdate(const common::UpdateInfo & _info);
		const std::string& getEstado() const {
			return estado;
		}
		void mover(std::string laUnion, double valor);
		void parametrizar(std::string laUnion,std::string tipo, double valor);
		void pintar(std::string);
		void cargarUniones();
	};
}
#endif
