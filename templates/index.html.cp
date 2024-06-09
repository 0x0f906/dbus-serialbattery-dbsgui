<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Config Editor</title>
    <link rel="stylesheet" href="/css/styles.css">
</head>
<body>
    <div class="container">
        <h1 class="my-4">Config Editor</h1>
        <form action="/update" method="post">
            <h2>Battery/Critical Setup</h2>
            <div class="form-group">
                <label for="MAX_BATTERY_CHARGE_CURRENT">Max Battery Charge Current:</label>
                <input type="text" class="form-control" name="MAX_BATTERY_CHARGE_CURRENT" value="{{ config.MAX_BATTERY_CHARGE_CURRENT }}">
            </div>
            <div class="form-group">
                <label for="MAX_BATTERY_DISCHARGE_CURRENT">Max Battery Discharge Current:</label>
                <input type="text" class="form-control" name="MAX_BATTERY_DISCHARGE_CURRENT" value="{{ config.MAX_BATTERY_DISCHARGE_CURRENT }}">
            </div>
            <div class="form-group">
                <label for="MIN_CELL_VOLTAGE">Min Cell Voltage:</label>
                <input type="text" class="form-control" name="MIN_CELL_VOLTAGE" value="{{ config.MIN_CELL_VOLTAGE }}">
            </div>
            <div class="form-group">
                <label for="MAX_CELL_VOLTAGE">Max Cell Voltage:</label>
                <input type="text" class="form-control" name="MAX_CELL_VOLTAGE" value="{{ config.MAX_CELL_VOLTAGE }}">
            </div>
            <div class="form-group">
                <label for="SOC_RESET_VOLTAGE">SOC Reset Voltage:</label>
                <input type="text" class="form-control" name="SOC_RESET_VOLTAGE" value="{{ config.SOC_RESET_VOLTAGE }}">
            </div>
            <div class="form-group">
                <label for="SOC_RESET_AFTER_DAYS">SOC Reset After Days:</label>
                <input type="text" class="form-control" name="SOC_RESET_AFTER_DAYS" value="{{ config.SOC_RESET_AFTER_DAYS }}">
            </div>
            <div class="form-group">
                <label for="BLOCK_ON_DISCONNECT">Block On Disconnect:</label>
                <select class="form-control" name="BLOCK_ON_DISCONNECT">
                    <option value="True" {% if config.BLOCK_ON_DISCONNECT == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.BLOCK_ON_DISCONNECT == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="VOLTAGE_DROP">Voltage Drop:</label>
                <input type="text" class="form-control" name="VOLTAGE_DROP" value="{{ config.VOLTAGE_DROP }}">
            </div>

            <h2>Charging</h2>
            <div class="form-group">
                <label for="FLOAT_CELL_VOLTAGE">Float Cell Voltage:</label>
                <input type="text" class="form-control" name="FLOAT_CELL_VOLTAGE" value="{{ config.FLOAT_CELL_VOLTAGE }}">
            </div>
            <div class="form-group">
                <label for="LINEAR_LIMITATION_ENABLE">Linear Limitation Enable:</label>
                <select class="form-control" name="LINEAR_LIMITATION_ENABLE">
                    <option value="True" {% if config.LINEAR_LIMITATION_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.LINEAR_LIMITATION_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="LINEAR_RECALCULATION_EVERY">Linear Recalculation Every:</label>
                <input type="text" class="form-control" name="LINEAR_RECALCULATION_EVERY" value="{{ config.LINEAR_RECALCULATION_EVERY }}">
            </div>
            <div class="form-group">
                <label for="LINEAR_RECALCULATION_ON_PERC_CHANGE">Linear Recalculation On Perc Change:</label>
                <input type="text" class="form-control" name="LINEAR_RECALCULATION_ON_PERC_CHANGE" value="{{ config.LINEAR_RECALCULATION_ON_PERC_CHANGE }}">
            </div>
            <div class="form-group">
                <label for="CVCM_ENABLE">CVCM Enable:</label>
                <select class="form-control" name="CVCM_ENABLE">
                    <option value="True" {% if config.CVCM_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.CVCM_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="CELL_VOLTAGE_DIFF_KEEP_MAX_VOLTAGE_UNTIL">Cell Voltage Diff Keep Max Voltage Until:</label>
                <input type="text" class="form-control" name="CELL_VOLTAGE_DIFF_KEEP_MAX_VOLTAGE_UNTIL" value="{{ config.CELL_VOLTAGE_DIFF_KEEP_MAX_VOLTAGE_UNTIL }}">
            </div>
            <div class="form-group">
                <label for="CELL_VOLTAGE_DIFF_KEEP_MAX_VOLTAGE_TIME_RESTART">Cell Voltage Diff Keep Max Voltage Time Restart:</label>
                <input type="text" class="form-control" name="CELL_VOLTAGE_DIFF_KEEP_MAX_VOLTAGE_TIME_RESTART" value="{{ config.CELL_VOLTAGE_DIFF_KEEP_MAX_VOLTAGE_TIME_RESTART }}">
            </div>
            <div class="form-group">
                <label for="CELL_VOLTAGE_DIFF_TO_RESET_VOLTAGE_LIMIT">Cell Voltage Diff To Reset Voltage Limit:</label>
                <input type="text" class="form-control" name="CELL_VOLTAGE_DIFF_TO_RESET_VOLTAGE_LIMIT" value="{{ config.CELL_VOLTAGE_DIFF_TO_RESET_VOLTAGE_LIMIT }}">
            </div>
            <div class="form-group">
                <label for="MAX_VOLTAGE_TIME_SEC">Max Voltage Time Sec:</label>
                <input type="text" class="form-control" name="MAX_VOLTAGE_TIME_SEC" value="{{ config.MAX_VOLTAGE_TIME_SEC }}">
            </div>
            <div class="form-group">
                <label for="SOC_LEVEL_TO_RESET_VOLTAGE_LIMIT">SOC Level To Reset Voltage Limit:</label>
                <input type="text" class="form-control" name="SOC_LEVEL_TO_RESET_VOLTAGE_LIMIT" value="{{ config.SOC_LEVEL_TO_RESET_VOLTAGE_LIMIT }}">
            </div>
            <div class="form-group">
                <label for="CCCM_CV_ENABLE">CCCM CV Enable:</label>
                <select class="form-control" name="CCCM_CV_ENABLE">
                    <option value="True" {% if config.CCCM_CV_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.CCCM_CV_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="CELL_VOLTAGES_WHILE_CHARGING">Cell Voltages While Charging:</label>
                <input type="text" class="form-control" name="CELL_VOLTAGES_WHILE_CHARGING" value="{{ config.CELL_VOLTAGES_WHILE_CHARGING }}">
            </div>
            <div class="form-group">
                <label for="MAX_CHARGE_CURRENT_CV_FRACTION">Max Charge Current CV Fraction:</label>
                <input type="text" class="form-control" name="MAX_CHARGE_CURRENT_CV_FRACTION" value="{{ config.MAX_CHARGE_CURRENT_CV_FRACTION }}">
            </div>
            <div class="form-group">
                <label for="CVL_ICONTROLLER_MODE">CVL Icontroller Mode:</label>
                <select class="form-control" name="CVL_ICONTROLLER_MODE">
                    <option value="True" {% if config.CVL_ICONTROLLER_MODE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.CVL_ICONTROLLER_MODE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="CVL_ICONTROLLER_FACTOR">CVL Icontroller Factor:</label>
                <input type="text" class="form-control" name="CVL_ICONTROLLER_FACTOR" value="{{ config.CVL_ICONTROLLER_FACTOR }}">
            </div>
            <div class="form-group">
                <label for="CCCM_SOC_ENABLE">CCCM SOC Enable:</label>
                <select class="form-control" name="CCCM_SOC_ENABLE">
                    <option value="True" {% if config.CCCM_SOC_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.CCCM_SOC_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="SOC_WHILE_CHARGING">SOC While Charging:</label>
                <input type="text" class="form-control" name="SOC_WHILE_CHARGING" value="{{ config.SOC_WHILE_CHARGING }}">
            </div>
            <div class="form-group">
                <label for="MAX_CHARGE_CURRENT_SOC_FRACTION">Max Charge Current SOC Fraction:</label>
                <input type="text" class="form-control" name="MAX_CHARGE_CURRENT_SOC_FRACTION" value="{{ config.MAX_CHARGE_CURRENT_SOC_FRACTION }}">
            </div>

            <h2>Discharging</h2>
            <div class="form-group">
                <label for="DCCM_CV_ENABLE">DCCM CV Enable:</label>
                <select class="form-control" name="DCCM_CV_ENABLE">
                    <option value="True" {% if config.DCCM_CV_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.DCCM_CV_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="CELL_VOLTAGES_WHILE_DISCHARGING">Cell Voltages While Discharging:</label>
                <input type="text" class="form-control" name="CELL_VOLTAGES_WHILE_DISCHARGING" value="{{ config.CELL_VOLTAGES_WHILE_DISCHARGING }}">
            </div>
            <div class="form-group">
                <label for="MAX_DISCHARGE_CURRENT_CV_FRACTION">Max Discharge Current CV Fraction:</label>
                <input type="text" class="form-control" name="MAX_DISCHARGE_CURRENT_CV_FRACTION" value="{{ config.MAX_DISCHARGE_CURRENT_CV_FRACTION }}">
            </div>
            <div class="form-group">
                <label for="DCCM_SOC_ENABLE">DCCM SOC Enable:</label>
                <select class="form-control" name="DCCM_SOC_ENABLE">
                    <option value="True" {% if config.DCCM_SOC_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.DCCM_SOC_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="SOC_WHILE_DISCHARGING">SOC While Discharging:</label>
                <input type="text" class="form-control" name="SOC_WHILE_DISCHARGING" value="{{ config.SOC_WHILE_DISCHARGING }}">
            </div>
            <div class="form-group">
                <label for="MAX_DISCHARGE_CURRENT_SOC_FRACTION">Max Discharge Current SOC Fraction:</label>
                <input type="text" class="form-control" name="MAX_DISCHARGE_CURRENT_SOC_FRACTION" value="{{ config.MAX_DISCHARGE_CURRENT_SOC_FRACTION }}">
            </div>

            <h2>Thermal</h2>
            <div class="form-group">
                <label for="CCCM_T_ENABLE">CCCM T Enable:</label>
                <select class="form-control" name="CCCM_T_ENABLE">
                    <option value="True" {% if config.CCCM_T_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.CCCM_T_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="DCCM_T_ENABLE">DCCM T Enable:</label>
                <select class="form-control" name="DCCM_T_ENABLE">
                    <option value="True" {% if config.DCCM_T_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.DCCM_T_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="TEMPERATURES_WHILE_CHARGING">Temperatures While Charging:</label>
                <input type="text" class="form-control" name="TEMPERATURES_WHILE_CHARGING" value="{{ config.TEMPERATURES_WHILE_CHARGING }}">
            </div>
            <div class="form-group">
                <label for="MAX_CHARGE_CURRENT_T_FRACTION">Max Charge Current T Fraction:</label>
                <input type="text" class="form-control" name="MAX_CHARGE_CURRENT_T_FRACTION" value="{{ config.MAX_CHARGE_CURRENT_T_FRACTION }}">
            </div>
            <div class="form-group">
                <label for="TEMPERATURES_WHILE_DISCHARGING">Temperatures While Discharging:</label>
                <input type="text" class="form-control" name="TEMPERATURES_WHILE_DISCHARGING" value="{{ config.TEMPERATURES_WHILE_DISCHARGING }}">
            </div>
            <div class="form-group">
                <label for="MAX_DISCHARGE_CURRENT_T_FRACTION">Max Discharge Current T Fraction:</label>
                <input type="text" class="form-control" name="MAX_DISCHARGE_CURRENT_T_FRACTION" value="{{ config.MAX_DISCHARGE_CURRENT_T_FRACTION }}">
            </div>
            <div class="form-group">
                <label for="TEMP_BATTERY">Battery Temperature Assembly:</label>
                <input type="text" class="form-control" name="TEMP_BATTERY" value="{{ config.TEMP_BATTERY }}">
            </div>
            <div class="form-group">
                <label for="TEMP_1_NAME">Temperature Sensor 1 Name:</label>
                <input type="text" class="form-control" name="TEMP_1_NAME" value="{{ config.TEMP_1_NAME }}">
            </div>
            <div class="form-group">
                <label for="TEMP_2_NAME">Temperature Sensor 2 Name:</label>
                <input type="text" class="form-control" name="TEMP_2_NAME" value="{{ config.TEMP_2_NAME }}">
            </div>
            <div class="form-group">
                <label for="TEMP_3_NAME">Temperature Sensor 3 Name:</label>
                <input type="text" class="form-control" name="TEMP_3_NAME" value="{{ config.TEMP_3_NAME }}">
            </div>
            <div class="form-group">
                <label for="TEMP_4_NAME">Temperature Sensor 4 Name:</label>
                <input type="text" class="form-control" name="TEMP_4_NAME" value="{{ config.TEMP_4_NAME }}">
            </div>

            <h2>BMS Setup</h2>
            <div class="form-group">
                <label for="BMS_TYPE">BMS Type:</label>
                <input type="text" class="form-control" name="BMS_TYPE" value="{{ config.BMS_TYPE }}">
            </div>
            <div class="form-group">
                <label for="BLUETOOTH_BMS">Bluetooth BMS:</label>
                <input type="text" class="form-control" name="BLUETOOTH_BMS" value="{{ config.BLUETOOTH_BMS }}">
            </div>
            <div class="form-group">
                <label for="CAN_PORT">CAN Port:</label>
                <input type="text" class="form-control" name="CAN_PORT" value="{{ config.CAN_PORT }}">
            </div>
            <div class="form-group">
                <label for="BLUETOOTH_USE_USB">Bluetooth Use USB:</label>
                <select class="form-control" name="BLUETOOTH_USE_USB">
                    <option value="True" {% if config.BLUETOOTH_USE_USB == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.BLUETOOTH_USE_USB == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="EXCLUDED_DEVICES">Excluded Devices:</label>
                <input type="text" class="form-control" name="EXCLUDED_DEVICES" value="{{ config.EXCLUDED_DEVICES }}">
            </div>
            <div class="form-group">
                <label for="USE_PORT_AS_UNIQUE_ID">Use Port As Unique ID:</label>
                <select class="form-control" name="USE_PORT_AS_UNIQUE_ID">
                    <option value="True" {% if config.USE_PORT_AS_UNIQUE_ID == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.USE_PORT_AS_UNIQUE_ID == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="SOC_LOW_WARNING">SOC Low Warning:</label>
                <input type="text" class="form-control" name="SOC_LOW_WARNING" value="{{ config.SOC_LOW_WARNING }}">
            </div>
            <div class="form-group">
                <label for="SOC_LOW_ALARM">SOC Low Alarm:</label>
                <input type="text" class="form-control" name="SOC_LOW_ALARM" value="{{ config.SOC_LOW_ALARM }}">
            </div>
            <div class="form-group">
                <label for="BATTERY_CAPACITY">Battery Capacity:</label>
                <input type="text" class="form-control" name="BATTERY_CAPACITY" value="{{ config.BATTERY_CAPACITY }}">
            </div>
            <div class="form-group">
                <label for="INVERT_CURRENT_MEASUREMENT">Invert Current Measurement:</label>
                <input type="text" class="form-control" name="INVERT_CURRENT_MEASUREMENT" value="{{ config.INVERT_CURRENT_MEASUREMENT }}">
            </div>
            <div class="form-group">
                <label for="JKBMS_CAN_CELL_COUNT">JKBMS CAN Cell Count:</label>
                <input type="text" class="form-control" name="JKBMS_CAN_CELL_COUNT" value="{{ config.JKBMS_CAN_CELL_COUNT }}">
            </div>
            <div class="form-group">
                <label for="GREENMETER_ADDRESS">GreenMeter Address:</label>
                <input type="text" class="form-control" name="GREENMETER_ADDRESS" value="{{ config.GREENMETER_ADDRESS }}">
            </div>
            <div class="form-group">
                <label for="LIPRO_START_ADDRESS">Lipro Start Address:</label>
                <input type="text" class="form-control" name="LIPRO_START_ADDRESS" value="{{ config.LIPRO_START_ADDRESS }}">
            </div>
            <div class="form-group">
                <label for="LIPRO_END_ADDRESS">Lipro End Address:</label>
                <input type="text" class="form-control" name="LIPRO_END_ADDRESS" value="{{ config.LIPRO_END_ADDRESS }}">
            </div>
            <div class="form-group">
                <label for="LIPRO_CELL_COUNT">Lipro Cell Count:</label>
                <input type="text" class="form-control" name="LIPRO_CELL_COUNT" value="{{ config.LIPRO_CELL_COUNT }}">
            </div>
            <div class="form-group">
                <label for="HELTEC_MODBUS_ADDR">Heltec Modbus Address:</label>
                <input type="text" class="form-control" name="HELTEC_MODBUS_ADDR" value="{{ config.HELTEC_MODBUS_ADDR }}">
            </div>
            <div class="form-group">
                <label for="SEPLOS_USE_BMS_VALUES">Seplos Use BMS Values:</label>
                <select class="form-control" name="SEPLOS_USE_BMS_VALUES">
                    <option value="True" {% if config.SEPLOS_USE_BMS_VALUES == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.SEPLOS_USE_BMS_VALUES == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>

            <h2>Driver Setup</h2>
            <div class="form-group">
                <label for="LOGGING">Logging:</label>
                <select class="form-control" name="LOGGING">
                    <option value="ERROR" {% if config.LOGGING == 'ERROR' %} selected {% endif %}>ERROR</option>
                    <option value="WARNING" {% if config.LOGGING == 'WARNING' %} selected {% endif %}>WARNING</option>
                    <option value="INFO" {% if config.LOGGING == 'INFO' %} selected {% endif %}>INFO</option>
                    <option value="DEBUG" {% if config.LOGGING == 'DEBUG' %} selected {% endif %}>DEBUG</option>
                </select>
            </div>
            <div class="form-group">
                <label for="EXTERNAL_CURRENT_SENSOR_DBUS_DEVICE">External Current Sensor DBus Device:</label>
                <input type="text" class="form-control" name="EXTERNAL_CURRENT_SENSOR_DBUS_DEVICE" value="{{ config.EXTERNAL_CURRENT_SENSOR_DBUS_DEVICE }}">
            </div>
            <div class="form-group">
                <label for="EXTERNAL_CURRENT_SENSOR_DBUS_PATH">External Current Sensor DBus Path:</label>
                <input type="text" class="form-control" name="EXTERNAL_CURRENT_SENSOR_DBUS_PATH" value="{{ config.EXTERNAL_CURRENT_SENSOR_DBUS_PATH }}">
            </div>
            <div class="form-group">
                <label for="SOC_CALCULATION">SOC Calculation:</label>
                <select class="form-control" name="SOC_CALCULATION">
                    <option value="True" {% if config.SOC_CALCULATION == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.SOC_CALCULATION == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="SOC_RESET_CURRENT">SOC Reset Current:</label>
                <input type="text" class="form-control" name="SOC_RESET_CURRENT" value="{{ config.SOC_RESET_CURRENT }}">
            </div>
            <div class="form-group">
                <label for="SOC_RESET_TIME">SOC Reset Time:</label>
                <input type="text" class="form-control" name="SOC_RESET_TIME" value="{{ config.SOC_RESET_TIME }}">
            </div>
            <div class="form-group">
                <label for="SOC_CALC_CURRENT_REPORTED_BY_BMS">SOC Calc Current Reported by BMS:</label>
                <input type="text" class="form-control" name="SOC_CALC_CURRENT_REPORTED_BY_BMS" value="{{ config.SOC_CALC_CURRENT_REPORTED_BY_BMS }}">
            </div>
            <div class="form-group">
                <label for="SOC_CALC_CURRENT_MEASURED_BY_USER">SOC Calc Current Measured by User:</label>
                <input type="text" class="form-control" name="SOC_CALC_CURRENT_MEASURED_BY_USER" value="{{ config.SOC_CALC_CURRENT_MEASURED_BY_USER }}">
            </div>
            <div class="form-group">
                <label for="TIME_TO_GO_ENABLE">Time to Go Enable:</label>
                <select class="form-control" name="TIME_TO_GO_ENABLE">
                    <option value="True" {% if config.TIME_TO_GO_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.TIME_TO_GO_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="TIME_TO_SOC_POINTS">Time to SOC Points:</label>
                <input type="text" class="form-control" name="TIME_TO_SOC_POINTS" value="{{ config.TIME_TO_SOC_POINTS }}">
            </div>
            <div class="form-group">
                <label for="TIME_TO_SOC_VALUE_TYPE">Time to SOC Value Type:</label>
                <input type="text" class="form-control" name="TIME_TO_SOC_VALUE_TYPE" value="{{ config.TIME_TO_SOC_VALUE_TYPE }}">
            </div>
            <div class="form-group">
                <label for="TIME_TO_SOC_RECALCULATE_EVERY">Time to SOC Recalculate Every:</label>
                <input type="text" class="form-control" name="TIME_TO_SOC_RECALCULATE_EVERY" value="{{ config.TIME_TO_SOC_RECALCULATE_EVERY }}">
            </div>
            <div class="form-group">
                <label for="TIME_TO_SOC_INC_FROM">Time to SOC Inc From:</label>
                <select class="form-control" name="TIME_TO_SOC_INC_FROM">
                    <option value="True" {% if config.TIME_TO_SOC_INC_FROM == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.TIME_TO_SOC_INC_FROM == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="POLL_INTERVAL">Poll Interval:</label>
                <input type="text" class="form-control" name="POLL_INTERVAL" value="{{ config.POLL_INTERVAL }}">
            </div>
            <div class="form-group">
                <label for="AUTO_RESET_SOC">Auto Reset SOC:</label>
                <select class="form-control" name="AUTO_RESET_SOC">
                    <option value="True" {% if config.AUTO_RESET_SOC == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.AUTO_RESET_SOC == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="PUBLISH_CONFIG_VALUES">Publish Config Values:</label>
                <select class="form-control" name="PUBLISH_CONFIG_VALUES">
                    <option value="True" {% if config.PUBLISH_CONFIG_VALUES == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.PUBLISH_CONFIG_VALUES == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>
            <div class="form-group">
                <label for="BATTERY_CELL_DATA_FORMAT">Battery Cell Data Format:</label>
                <input type="text" class="form-control" name="BATTERY_CELL_DATA_FORMAT" value="{{ config.BATTERY_CELL_DATA_FORMAT }}">
            </div>
            <div class="form-group">
                <label for="MIDPOINT_ENABLE">Midpoint Enable:</label>
                <select class="form-control" name="MIDPOINT_ENABLE">
                    <option value="True" {% if config.MIDPOINT_ENABLE == 'True' %} selected {% endif %}>True</option>
                    <option value="False" {% if config.MIDPOINT_ENABLE == 'False' %} selected {% endif %}>False</option>
                </select>
            </div>

            <button type="submit" class="btn btn-primary">Update</button>
        </form>
    </div>
</body>
</html>
