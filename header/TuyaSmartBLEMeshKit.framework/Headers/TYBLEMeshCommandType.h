//
// TYBLEMeshCommandType.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TYBLEMeshCommandType_h
#define TYBLEMeshCommandType_h

/// The ble mesh command type.
typedef NS_ENUM(NSUInteger, TYBLEMeshCommandType) {
    
    /// Modify device address.
    TYBLEMeshSetDeviceAddressCommand = 0xAA,
    
    /// Group operations, such as adding, deleting, and adding devices to a group.
    TYBLEMeshGroupHandlingCommand,
    
    /// Get the address of the device group.
    TYBLEMeshFetchGroupAddressCommand,
    
    /// Kick the device out of the network.
    TYBLEMeshKickedOutCommand,
    
    /// Get the ID of all devices in the group.
    TYBLEMeshFetchAllDeviceIdFromGroupCommand,
    
    /// Request auth key.
    TYBLEMeshRequestAuthKeyCommand,
    
    /// Switch command.
    TYBLEMeshTurnOnAndOffCommand,
    
    /// Get status of all devices in mesh.
    TYBLEMeshFetchAllStateCommand,
    
    /// Set brightness value.
    TYBLEMeshSetBrightnessValueCommand,
    
    /// Set RGBWCL value.
    TYBLEMeshSetRGBWCLCommand,
    
    /// Set the light on mode, color light / white light.
    TYBLEMeshSetLightModelCommand,
    
    /// Control sub row insertion.
    TYBLEMeshControlSubSwitchCommand,
    
    /// Set countdown.
    TYBLEMeshSetCountDownCommand,
    
    /// Read countdown.
    TYBLEMeshFetchCountDownCommand,
    
    /// Read sensor value.
    TYBLEMeshFetchSensorValueCommand,
    
    /// Send DP point.
    TYBLEMeshSendDPSCommand,
    
    /// Gets one or two states.
    TYBLEMeshFetchStateCommand,
    
    /// Modify the current mesh light scene mode data.
    TYBLEMeshSetLightSceneModelCommand,
    
    /// Get the current mesh light scene mode data.
    TYBLEMeshGetLightSceneModelCommand,
    
    /// time synchronization.
    TYBLEMeshTimeSynchronizationCommand,
    
    /// Setting timing.
    TYBLEMeshSetTimerCommand,
    
    /// Read timing.
    TYBLEMeshGetTimerCommand,
    
};

#endif /* TYBLEMeshCommandType_h */
