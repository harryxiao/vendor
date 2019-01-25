/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SensorHubOpCodeExtrator.h"

static struct iic_unit eCmdInitArray[] = {
};

static struct iic_unit eCmdEnableArray[] = {
  {
    .operate = 0x02, .addr = 0x6B, .val = 0x01, .mask = 0x5F,
  },
  {
    .operate = 0x04, .addr = 0x00, .val = 0x00, .mask = 0x0A,
  },
  {
    .operate = 0x02, .addr = 0x6C, .val = 0x00, .mask = 0x07,
  },
  {
    .operate = 0x02, .addr = 0x1B, .val = 0x18, .mask = 0x18,
  },
  {
    .operate = 0x02, .addr = 0x1A, .val = 0x02, .mask = 0x07,
  },
};

static struct iic_unit eCmdDisableArray[] = {
  {
    .operate = 0x02, .addr = 0x6C, .val = 0x07, .mask = 0x07,
  },
  {
    .operate = 0x03, .addr = 0x6C, .val = 0x38, .mask = 0x38,
  },
  {
    .operate = 0x02, .addr = 0x6B, .val = 0x48, .mask = 0x48,
  },
  {
    .operate = 0x04, .addr = 0x00, .val = 0x00, .mask = 0x0A,
  },
};

static struct iic_unit eCmdGetRawDataArray[] = {
  {
    .operate = 0x01, .addr = 0x44, .val = 0x00, .mask = 0xFF,
  },
  {
    .operate = 0x01, .addr = 0x43, .val = 0x00, .mask = 0xFF,
  },
  {
    .operate = 0x01, .addr = 0x46, .val = 0x00, .mask = 0xFF,
  },
  {
    .operate = 0x01, .addr = 0x45, .val = 0x00, .mask = 0xFF,
  },
  {
    .operate = 0x01, .addr = 0x48, .val = 0x00, .mask = 0xFF,
  },
  {
    .operate = 0x01, .addr = 0x47, .val = 0x00, .mask = 0xFF,
  },
};

static struct iic_unit eCmdGetFifoDataArray[] = {
};

static struct iic_unit eCmdGetStatusArray[] = {
};

static struct iic_unit eCmdSetStatusArray[] = {
};

static struct iic_unit eCmdSetSelftestArray[] = {
};

static struct iic_unit eCmdSetOffsetArray[] = {
};

static struct iic_unit eCmdSetRateArray[] = {
  {
    .operate = 0x02, .addr = 0x19, .val = 0x09, .mask = 0xFF,
  },
  {
    .operate = 0x02, .addr = 0x19, .val = 0x13, .mask = 0xFF,
  },
  {
    .operate = 0x02, .addr = 0x19, .val = 0x3D, .mask = 0xFF,
  },
  {
    .operate = 0x02, .addr = 0x19, .val = 0xC7, .mask = 0xFF,
  },
  {
    .operate = 0x04, .addr = 0x00, .val = 0x01, .mask = 0xC8,
  },
};

static struct iic_unit eCmdSetModeArray[] = {
};

static struct iic_unit eCmdSetSettingArray[] = {
};

static struct iic_unit eCmdCheckIdArray[] = {
  {
    .operate = 0x03, .addr = 0x75, .val = 0xAE, .mask = 0xFF,
  },
};

static struct iic_unit eCmdScanSlaveArray[] = {
};

static sensor_info_t sensorInfoConfigArray[] = {
  {
    .Interface      = 0,
    .Interface_Freq = 400,
    .ISR_Mode       = 0,
    .GPIO_ISR_Num   = 0,
    .Slave_Addr     = 0xD2,
    .Chip_Id        = 0xAE,
    .Resolution     = 0.001065f,
    .Range          = 0x7D0,
    .Postion        = 3,
    .Vendor         = 0,
  },
};

static struct opcode_unit sSensorOpcode[eCmdTotal] = {
  {
    .eCmd = CMD_HWINIT,
    .nIIcUnits = sizeof(eCmdInitArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdInitArray,
  },
  {
    .eCmd = CMD_ENABLE,
    .nIIcUnits = sizeof(eCmdEnableArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdEnableArray,
  },
  {
    .eCmd = CMD_DISABLE,
    .nIIcUnits = sizeof(eCmdDisableArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdDisableArray,
  },

  {
    .eCmd = CMD_GET_BYPASS,
    .nIIcUnits = sizeof(eCmdGetRawDataArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdGetRawDataArray,
  },
  {
    .eCmd = CMD_GET_FIFO,
    .nIIcUnits = sizeof(eCmdGetFifoDataArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdGetFifoDataArray,
  },
  {
    .eCmd = CMD_GET_STATUS,
    .nIIcUnits = sizeof(eCmdGetStatusArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdGetStatusArray,
  },
  {
    .eCmd = CMD_SET_STATUS,
    .nIIcUnits = sizeof(eCmdSetStatusArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdSetStatusArray,
  },
  {
    .eCmd = CMD_SET_SELFTEST,
    .nIIcUnits = sizeof(eCmdSetSelftestArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdSetSelftestArray,
  },
  {
    .eCmd = CMD_SET_OFFSET,
    .nIIcUnits = sizeof(eCmdSetOffsetArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdSetOffsetArray,
  },
  {
    .eCmd = CMD_SET_RATE,
    .nIIcUnits = sizeof(eCmdSetRateArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdSetRateArray,
  },
  {
    .eCmd = CMD_SET_MODE,
    .nIIcUnits = sizeof(eCmdSetModeArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdSetModeArray,
  },
  {
    .eCmd = CMD_SET_SETTING,
    .nIIcUnits = sizeof(eCmdSetSettingArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdSetSettingArray,
  },
  {
    .eCmd = CMD_CHECK_ID,
    .nIIcUnits = sizeof(eCmdCheckIdArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdCheckIdArray,
  },
  {
    .eCmd = CMD_SCANSALVE,
    .nIIcUnits = sizeof(eCmdScanSlaveArray) / sizeof(iic_unit_t),
    .pIIcUnits = eCmdScanSlaveArray,
  },
};

void SensorHubOpcodeRegisterGyroscope(void) {
  SensorHubOpcodeRegister("gyroscope", sensorInfoConfigArray, sSensorOpcode);
  return;
}
