#include <sun/security/jgss/GSSHeader.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/PrintStream.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>
#include <java/lang/System.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <org/ietf/jgss/GSSException.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <jcpp.h>

#undef DEFECTIVE_TOKEN
#undef TOKEN_ID

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $GSSException = ::org::ietf::jgss::GSSException;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;

namespace sun {
	namespace security {
		namespace jgss {

$FieldInfo _GSSHeader_FieldInfo_[] = {
	{"mechOid", "Lsun/security/util/ObjectIdentifier;", nullptr, $PRIVATE, $field(GSSHeader, mechOid)},
	{"mechOidBytes", "[B", nullptr, $PRIVATE, $field(GSSHeader, mechOidBytes)},
	{"mechTokenLength", "I", nullptr, $PRIVATE, $field(GSSHeader, mechTokenLength)},
	{"TOKEN_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(GSSHeader, TOKEN_ID)},
	{}
};

$MethodInfo _GSSHeader_MethodInfo_[] = {
	{"<init>", "(Lsun/security/util/ObjectIdentifier;I)V", nullptr, $PUBLIC, $method(static_cast<void(GSSHeader::*)($ObjectIdentifier*,int32_t)>(&GSSHeader::init$)), "java.io.IOException"},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(GSSHeader::*)($InputStream*)>(&GSSHeader::init$)), "java.io.IOException,org.ietf.jgss.GSSException"},
	{"debug", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(GSSHeader::*)($String*)>(&GSSHeader::debug))},
	{"encode", "(Ljava/io/OutputStream;)I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getHexBytes", "([BI)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(GSSHeader::*)($bytes*,int32_t)>(&GSSHeader::getHexBytes)), "java.io.IOException"},
	{"getLenFieldSize", "(I)I", nullptr, $PRIVATE, $method(static_cast<int32_t(GSSHeader::*)(int32_t)>(&GSSHeader::getLenFieldSize))},
	{"getLength", "()I", nullptr, $PUBLIC},
	{"getLength", "(Ljava/io/InputStream;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(GSSHeader::*)($InputStream*)>(&GSSHeader::getLength)), "java.io.IOException"},
	{"getLength", "(ILjava/io/InputStream;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(GSSHeader::*)(int32_t,$InputStream*)>(&GSSHeader::getLength)), "java.io.IOException"},
	{"getMaxMechTokenSize", "(Lsun/security/util/ObjectIdentifier;I)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($ObjectIdentifier*,int32_t)>(&GSSHeader::getMaxMechTokenSize))},
	{"getMechTokenLength", "()I", nullptr, $PUBLIC},
	{"getOid", "()Lsun/security/util/ObjectIdentifier;", nullptr, $PUBLIC},
	{"putLength", "(ILjava/io/OutputStream;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(GSSHeader::*)(int32_t,$OutputStream*)>(&GSSHeader::putLength)), "java.io.IOException"},
	{}
};

$ClassInfo _GSSHeader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.jgss.GSSHeader",
	"java.lang.Object",
	nullptr,
	_GSSHeader_FieldInfo_,
	_GSSHeader_MethodInfo_
};

$Object* allocate$GSSHeader($Class* clazz) {
	return $of($alloc(GSSHeader));
}

void GSSHeader::init$($ObjectIdentifier* mechOid, int32_t mechTokenLength) {
	$set(this, mechOid, nullptr);
	$set(this, mechOidBytes, nullptr);
	this->mechTokenLength = 0;
	$set(this, mechOid, mechOid);
	$var($DerOutputStream, temp, $new($DerOutputStream));
	temp->putOID(mechOid);
	$set(this, mechOidBytes, temp->toByteArray());
	this->mechTokenLength = mechTokenLength;
}

void GSSHeader::init$($InputStream* is) {
	$set(this, mechOid, nullptr);
	$set(this, mechOidBytes, nullptr);
	this->mechTokenLength = 0;
	int32_t tag = $nc(is)->read();
	if (tag != GSSHeader::TOKEN_ID) {
		$throwNew($GSSException, $GSSException::DEFECTIVE_TOKEN, -1, "GSSHeader did not find the right tag"_s);
	}
	int32_t length = getLength(is);
	$var($DerValue, temp, $new($DerValue, is));
	$set(this, mechOidBytes, temp->toByteArray());
	$set(this, mechOid, temp->getOID());
	this->mechTokenLength = length - $nc(this->mechOidBytes)->length;
}

$ObjectIdentifier* GSSHeader::getOid() {
	return this->mechOid;
}

int32_t GSSHeader::getMechTokenLength() {
	return this->mechTokenLength;
}

int32_t GSSHeader::getLength() {
	int32_t lenField = $nc(this->mechOidBytes)->length + this->mechTokenLength;
	return (1 + getLenFieldSize(lenField) + $nc(this->mechOidBytes)->length);
}

int32_t GSSHeader::getMaxMechTokenSize($ObjectIdentifier* mechOid, int32_t maxTotalSize) {
	int32_t mechOidBytesSize = 0;
	try {
		$var($DerOutputStream, temp, $new($DerOutputStream));
		temp->putOID(mechOid);
		mechOidBytesSize = $nc($(temp->toByteArray()))->length;
	} catch ($IOException&) {
		$catch();
	}
	maxTotalSize -= (1 + mechOidBytesSize);
	maxTotalSize -= 5;
	return maxTotalSize;
}

int32_t GSSHeader::getLenFieldSize(int32_t len) {
	int32_t retVal = 1;
	if (len < 128) {
		retVal = 1;
	} else if (len < (1 << 8)) {
		retVal = 2;
	} else if (len < (1 << 16)) {
		retVal = 3;
	} else if (len < (1 << 24)) {
		retVal = 4;
	} else {
		retVal = 5;
	}
	return retVal;
}

int32_t GSSHeader::encode($OutputStream* os) {
	int32_t retVal = 1 + $nc(this->mechOidBytes)->length;
	$nc(os)->write(GSSHeader::TOKEN_ID);
	int32_t length = $nc(this->mechOidBytes)->length + this->mechTokenLength;
	retVal += putLength(length, os);
	os->write(this->mechOidBytes);
	return retVal;
}

int32_t GSSHeader::getLength($InputStream* in) {
	return getLength($nc(in)->read(), in);
}

int32_t GSSHeader::getLength(int32_t lenByte, $InputStream* in) {
	int32_t value = 0;
	int32_t tmp = 0;
	tmp = lenByte;
	if (((int32_t)(tmp & (uint32_t)128)) == 0) {
		value = tmp;
	} else {
		tmp &= (uint32_t)127;
		if (tmp == 0) {
			return -1;
		}
		if (tmp < 0 || tmp > 4) {
			$throwNew($IOException, $$str({"DerInputStream.getLength(): lengthTag="_s, $$str(tmp), ", "_s, ((tmp < 0) ? "incorrect DER encoding."_s : "too big."_s)}));
		}
		for (value = 0; tmp > 0; --tmp) {
			value <<= 8;
			value += (int32_t)(255 & (uint32_t)$nc(in)->read());
		}
		if (value < 0) {
			$throwNew($IOException, "Invalid length bytes"_s);
		}
	}
	return value;
}

int32_t GSSHeader::putLength(int32_t len, $OutputStream* out) {
	int32_t retVal = 0;
	if (len < 128) {
		$nc(out)->write((int32_t)(int8_t)len);
		retVal = 1;
	} else if (len < (1 << 8)) {
		$nc(out)->write((int32_t)(int8_t)129);
		out->write((int32_t)(int8_t)len);
		retVal = 2;
	} else if (len < (1 << 16)) {
		$nc(out)->write((int32_t)(int8_t)130);
		out->write((int32_t)(int8_t)(len >> 8));
		out->write((int32_t)(int8_t)len);
		retVal = 3;
	} else if (len < (1 << 24)) {
		$nc(out)->write((int32_t)(int8_t)131);
		out->write((int32_t)(int8_t)(len >> 16));
		out->write((int32_t)(int8_t)(len >> 8));
		out->write((int32_t)(int8_t)len);
		retVal = 4;
	} else {
		$nc(out)->write((int32_t)(int8_t)132);
		out->write((int32_t)(int8_t)(len >> 24));
		out->write((int32_t)(int8_t)(len >> 16));
		out->write((int32_t)(int8_t)(len >> 8));
		out->write((int32_t)(int8_t)len);
		retVal = 5;
	}
	return retVal;
}

void GSSHeader::debug($String* str) {
	$init($System);
	$nc($System::err)->print(str);
}

$String* GSSHeader::getHexBytes($bytes* bytes, int32_t len) {
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t i = 0; i < len; ++i) {
		int32_t b1 = (int32_t)(($nc(bytes)->get(i) >> 4) & (uint32_t)15);
		int32_t b2 = (int32_t)(bytes->get(i) & (uint32_t)15);
		sb->append($($Integer::toHexString(b1)));
		sb->append($($Integer::toHexString(b2)));
		sb->append(u' ');
	}
	return sb->toString();
}

GSSHeader::GSSHeader() {
}

$Class* GSSHeader::load$($String* name, bool initialize) {
	$loadClass(GSSHeader, name, initialize, &_GSSHeader_ClassInfo_, allocate$GSSHeader);
	return class$;
}

$Class* GSSHeader::class$ = nullptr;

		} // jgss
	} // security
} // sun