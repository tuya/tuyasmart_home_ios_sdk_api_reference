//
// TYBLEMeshCommand.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TYBLEMeshCommandType.h"

/// The mesh command protocol, confirm and impl some command, will execute.=====The mesh command protocol that is used to confirm and implement certain commands.
@protocol TYBLEMeshCommandProtocol <NSObject>

/// Convert to Bluetooth command.=====Converts to the Bluetooth command.
/// @return The Bluetooth command.
- (NSData *)command;

/// Converts  to the raw command that is used by a gateway.
/// @return The raw command.
- (NSString *)raw;

@end

/// @brief The ble mesh command for some command.=======The Bluetooth mesh protocol for certain commands.
@interface TYBLEMeshCommand : NSObject <TYBLEMeshCommandProtocol>

/// The command type.
@property (nonatomic, assign) TYBLEMeshCommandType commandType;

/// For equipment type, the small category is in the front, and the major category is in the rear, for example, four street lamps. At this time, the PCC is 0401 "04 represents four street lamps, 01 represents major categories of lamps".
@property (nonatomic, strong) NSString *pcc;

/// Device or group address, device address range (1-255), group address range 0x8001-0x8008.
@property (nonatomic, assign) uint32_t address;

/// Is it a group command.
@property (nonatomic, assign) BOOL isGroup;

/// For command data, refer to the document.
@property (nonatomic, strong) NSArray<NSString *> *dataParams;

/// Secondary log output.
@property (nonatomic, strong) NSString *logDescription;

@end
