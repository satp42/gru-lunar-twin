# Battery status message for fleet power management
std_msgs/Header header
string unit_id              # Unit/vehicle identifier
float64 soc_percentage      # State of Charge (0-100%)
float64 voltage_v           # Battery voltage in volts
bool charging               # Charging status 