#include <gz/sim/System.hh>
#include <gz/sim/components/Gravity.hh>
#include <gz/sim/components/World.hh>
#include <gz/transport/Node.hh>
#include <gz/msgs/vector3d.pb.h>

namespace gravity_scale_plugin
{
  class GravityScalePlugin :
    public gz::sim::System,
    public gz::sim::ISystemConfigure,
    public gz::sim::ISystemPostUpdate
  {
    public: void Configure(const gz::sim::Entity &_entity,
        const std::shared_ptr<const sdf::Element> &_sdf,
        gz::sim::EntityComponentManager &_ecm,
        gz::sim::EventManager &) override
    {
      this->worldEntity = _entity;
      
      if (_sdf->HasElement("scale"))
      {
        this->scale = _sdf->Get<double>("scale");
      }
      
      this->pub = this->node.Advertise<gz::msgs::Vector3d>("/world/gravity");
    }

    public: void PostUpdate(const gz::sim::UpdateInfo &,
        const gz::sim::EntityComponentManager &_ecm) override
    {
      auto gravityComp = _ecm.Component<gz::sim::components::Gravity>(this->worldEntity);
      if (gravityComp)
      {
        auto gravity = gravityComp->Data();
        
        gz::msgs::Vector3d gravityMsg;
        gravityMsg.set_x(gravity.X() * this->scale);
        gravityMsg.set_y(gravity.Y() * this->scale);
        gravityMsg.set_z(gravity.Z() * this->scale);
        
        this->pub.Publish(gravityMsg);
      }
    }

    private: gz::sim::Entity worldEntity;
    private: double scale = 1.0;
    private: gz::transport::Node node;
    private: gz::transport::Node::Publisher pub;
  };
}

#include <gz/plugin/Register.hh>
GZ_ADD_PLUGIN(
  gravity_scale_plugin::GravityScalePlugin,
  gz::sim::System,
  gravity_scale_plugin::GravityScalePlugin::ISystemConfigure,
  gravity_scale_plugin::GravityScalePlugin::ISystemPostUpdate) 