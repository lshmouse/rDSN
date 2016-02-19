/**
 * Autogenerated by Thrift Compiler ()
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include <dsn/dist/failure_detector/fd_types.h>

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace dsn { namespace fd {


beacon_msg::~beacon_msg() throw() {
}


void beacon_msg::__set_time(const int64_t val) {
  this->time = val;
}

void beacon_msg::__set_from(const  ::dsn::rpc_address& val) {
  this->from = val;
}

void beacon_msg::__set_to(const  ::dsn::rpc_address& val) {
  this->to = val;
}

const char* beacon_msg::ascii_fingerprint = "C1553D56D339B9717EF283788B23652B";
const uint8_t beacon_msg::binary_fingerprint[16] = {0xC1,0x55,0x3D,0x56,0xD3,0x39,0xB9,0x71,0x7E,0xF2,0x83,0x78,0x8B,0x23,0x65,0x2B};

uint32_t beacon_msg::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->time);
          this->__isset.time = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->from.read(iprot);
          this->__isset.from = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->to.read(iprot);
          this->__isset.to = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t beacon_msg::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("beacon_msg");

  xfer += oprot->writeFieldBegin("time", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->time);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("from", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->from.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("to", ::apache::thrift::protocol::T_STRUCT, 3);
  xfer += this->to.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(beacon_msg &a, beacon_msg &b) {
  using ::std::swap;
  swap(a.time, b.time);
  swap(a.from, b.from);
  swap(a.to, b.to);
  swap(a.__isset, b.__isset);
}

beacon_msg::beacon_msg(const beacon_msg& other0) {
  time = other0.time;
  from = other0.from;
  to = other0.to;
  __isset = other0.__isset;
}
beacon_msg& beacon_msg::operator=(const beacon_msg& other1) {
  time = other1.time;
  from = other1.from;
  to = other1.to;
  __isset = other1.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const beacon_msg& obj) {
  using apache::thrift::to_string;
  out << "beacon_msg(";
  out << "time=" << to_string(obj.time);
  out << ", " << "from=" << to_string(obj.from);
  out << ", " << "to=" << to_string(obj.to);
  out << ")";
  return out;
}


beacon_ack::~beacon_ack() throw() {
}


void beacon_ack::__set_time(const int64_t val) {
  this->time = val;
}

void beacon_ack::__set_this_node(const  ::dsn::rpc_address& val) {
  this->this_node = val;
}

void beacon_ack::__set_primary_node(const  ::dsn::rpc_address& val) {
  this->primary_node = val;
}

void beacon_ack::__set_is_master(const bool val) {
  this->is_master = val;
}

void beacon_ack::__set_allowed(const bool val) {
  this->allowed = val;
}

const char* beacon_ack::ascii_fingerprint = "D681410B61D925467A524E160C7A0728";
const uint8_t beacon_ack::binary_fingerprint[16] = {0xD6,0x81,0x41,0x0B,0x61,0xD9,0x25,0x46,0x7A,0x52,0x4E,0x16,0x0C,0x7A,0x07,0x28};

uint32_t beacon_ack::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->time);
          this->__isset.time = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->this_node.read(iprot);
          this->__isset.this_node = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->primary_node.read(iprot);
          this->__isset.primary_node = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->is_master);
          this->__isset.is_master = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->allowed);
          this->__isset.allowed = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t beacon_ack::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("beacon_ack");

  xfer += oprot->writeFieldBegin("time", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->time);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("this_node", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->this_node.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("primary_node", ::apache::thrift::protocol::T_STRUCT, 3);
  xfer += this->primary_node.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("is_master", ::apache::thrift::protocol::T_BOOL, 4);
  xfer += oprot->writeBool(this->is_master);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("allowed", ::apache::thrift::protocol::T_BOOL, 5);
  xfer += oprot->writeBool(this->allowed);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(beacon_ack &a, beacon_ack &b) {
  using ::std::swap;
  swap(a.time, b.time);
  swap(a.this_node, b.this_node);
  swap(a.primary_node, b.primary_node);
  swap(a.is_master, b.is_master);
  swap(a.allowed, b.allowed);
  swap(a.__isset, b.__isset);
}

beacon_ack::beacon_ack(const beacon_ack& other2) {
  time = other2.time;
  this_node = other2.this_node;
  primary_node = other2.primary_node;
  is_master = other2.is_master;
  allowed = other2.allowed;
  __isset = other2.__isset;
}
beacon_ack& beacon_ack::operator=(const beacon_ack& other3) {
  time = other3.time;
  this_node = other3.this_node;
  primary_node = other3.primary_node;
  is_master = other3.is_master;
  allowed = other3.allowed;
  __isset = other3.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const beacon_ack& obj) {
  using apache::thrift::to_string;
  out << "beacon_ack(";
  out << "time=" << to_string(obj.time);
  out << ", " << "this_node=" << to_string(obj.this_node);
  out << ", " << "primary_node=" << to_string(obj.primary_node);
  out << ", " << "is_master=" << to_string(obj.is_master);
  out << ", " << "allowed=" << to_string(obj.allowed);
  out << ")";
  return out;
}

}} // namespace
