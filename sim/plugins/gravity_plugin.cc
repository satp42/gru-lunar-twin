#include <gz/sim/System.hh>
#include <gz/sim/components/Gravity.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/EventManager.hh>
#include <gz/transport/Node.hh>
#include <gz/msgs/vector3d.pb.h>
#include <gz/math/Vector3.hh>

using namespace gz;
using namespace sim;

namespace lunar_twin
{
  /// \brief A system plugin that sets lunar gravity (1/6 Earth gravity)
  /// and publishes the current gravity to /world/gravity topic
  class LunarGravityPlugin : public System,
                             public ISystemConfigure,
                             public ISystemPostUpdate
  {
    public: void Configure(const Entity &_entity,
                          const std::shared_ptr<const sdf::Element> &_sdf,
                          EntityComponentManager &_ecm,
                          EventManager &_eventMgr) override
    {
      // Store entity
      this->worldEntity = _entity;
      
      // Initialize transport node
      this->node = std::make_unique<transport::Node>();
      
      // Create publisher for gravity status
      this->gravityPub = this->node->Advertise<msgs::Vector3d>("/world/gravity");
      
      // Calculate lunar gravity (1/6 of Earth's gravity)
      this->lunarGravity = math::Vector3d(0.0, 0.0, -1.635);
      
      gzdbg << "LunarGravityPlugin: Setting gravity to lunar values: " 
            << this->lunarGravity << std::endl;
      
      // Set gravity component
      _ecm.CreateComponent(this->worldEntity, 
                          components::Gravity(this->lunarGravity));
    }

    public: void PostUpdate(const UpdateInfo &_info,
                           const EntityComponentManager &_ecm) override
    {
      // Publish gravity status periodically (every second)
      if (_info.simTime.count() - this->lastPublishTime.count() > 1000000000) // 1 second in nanoseconds
      {
        msgs::Vector3d gravityMsg;
        msgs::Set(&gravityMsg, this->lunarGravity);
        
        this->gravityPub.Publish(gravityMsg);
        this->lastPublishTime = _info.simTime;
        
        gzdbg << "Published gravity: " << this->lunarGravity << std::endl;
      }
    }

    private: Entity worldEntity;
    private: std::unique_ptr<transport::Node> node;
    private: transport::Node::Publisher gravityPub;
    private: math::Vector3d lunarGravity;
    private: std::chrono::steady_clock::duration lastPublishTime{0};
  };
}

// Register the plugin
GZ_ADD_PLUGIN(lunar_twin::LunarGravityPlugin,
              System,
              lunar_twin::LunarGravityPlugin::ISystemConfigure,
              lunar_twin::LunarGravityPlugin::ISystemPostUpdate) 