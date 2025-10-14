#include <sun/security/krb5/internal/PaPacOptions.h>

#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <sun/security/krb5/Asn1Exception.h>
#include <sun/security/krb5/internal/KDCOptions.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/util/KerberosFlags.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <jcpp.h>

#undef AP_OPTS_MAX
#undef ASN1_BAD_ID
#undef BRANCH_AWARE
#undef CLAIMS
#undef FORWARD_TO_FULL_DC
#undef RESOURCE_BASED_CONSTRAINED_DELEGATION
#undef TAG_CONTEXT

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Asn1Exception = ::sun::security::krb5::Asn1Exception;
using $KDCOptions = ::sun::security::krb5::internal::KDCOptions;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KerberosFlags = ::sun::security::krb5::internal::util::KerberosFlags;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {

$FieldInfo _PaPacOptions_FieldInfo_[] = {
	{"CLAIMS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PaPacOptions, CLAIMS)},
	{"BRANCH_AWARE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PaPacOptions, BRANCH_AWARE)},
	{"FORWARD_TO_FULL_DC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PaPacOptions, FORWARD_TO_FULL_DC)},
	{"RESOURCE_BASED_CONSTRAINED_DELEGATION", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PaPacOptions, RESOURCE_BASED_CONSTRAINED_DELEGATION)},
	{"flags", "Lsun/security/krb5/internal/util/KerberosFlags;", nullptr, $PRIVATE, $field(PaPacOptions, flags)},
	{}
};

$MethodInfo _PaPacOptions_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(PaPacOptions::*)()>(&PaPacOptions::init$))},
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(static_cast<void(PaPacOptions::*)($DerValue*)>(&PaPacOptions::init$)), "sun.security.krb5.Asn1Exception,java.io.IOException"},
	{"asn1Encode", "()[B", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getBranchAware", "()Z", nullptr, $PUBLIC},
	{"getClaims", "()Z", nullptr, $PUBLIC},
	{"getForwardToFullDC", "()Z", nullptr, $PUBLIC},
	{"getResourceBasedConstrainedDelegation", "()Z", nullptr, $PUBLIC},
	{"setBranchAware", "(Z)Lsun/security/krb5/internal/PaPacOptions;", nullptr, $PUBLIC},
	{"setClaims", "(Z)Lsun/security/krb5/internal/PaPacOptions;", nullptr, $PUBLIC},
	{"setForwardToFullDC", "(Z)Lsun/security/krb5/internal/PaPacOptions;", nullptr, $PUBLIC},
	{"setResourceBasedConstrainedDelegation", "(Z)Lsun/security/krb5/internal/PaPacOptions;", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _PaPacOptions_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.krb5.internal.PaPacOptions",
	"java.lang.Object",
	nullptr,
	_PaPacOptions_FieldInfo_,
	_PaPacOptions_MethodInfo_
};

$Object* allocate$PaPacOptions($Class* clazz) {
	return $of($alloc(PaPacOptions));
}

void PaPacOptions::init$() {
	$set(this, flags, $new($KerberosFlags, $Krb5::AP_OPTS_MAX + 1));
}

void PaPacOptions::init$($DerValue* encoding) {
	if ($nc(encoding)->getTag() != $DerValue::tag_Sequence) {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
	$var($DerValue, der, $nc($($nc(encoding)->getData()))->getDerValue());
	if (((int32_t)($nc(der)->getTag() & (uint32_t)31)) == 0) {
		$set(this, flags, $new($KDCOptions, $($nc($(der->getData()))->getDerValue())));
	} else {
		$throwNew($Asn1Exception, $Krb5::ASN1_BAD_ID);
	}
}

PaPacOptions* PaPacOptions::setClaims(bool value) {
	$nc(this->flags)->set(PaPacOptions::CLAIMS, value);
	return this;
}

bool PaPacOptions::getClaims() {
	return $nc(this->flags)->get(PaPacOptions::CLAIMS);
}

PaPacOptions* PaPacOptions::setBranchAware(bool value) {
	$nc(this->flags)->set(PaPacOptions::BRANCH_AWARE, value);
	return this;
}

bool PaPacOptions::getBranchAware() {
	return $nc(this->flags)->get(PaPacOptions::BRANCH_AWARE);
}

PaPacOptions* PaPacOptions::setForwardToFullDC(bool value) {
	$nc(this->flags)->set(PaPacOptions::FORWARD_TO_FULL_DC, value);
	return this;
}

bool PaPacOptions::getForwardToFullDC() {
	return $nc(this->flags)->get(PaPacOptions::FORWARD_TO_FULL_DC);
}

PaPacOptions* PaPacOptions::setResourceBasedConstrainedDelegation(bool value) {
	$nc(this->flags)->set(PaPacOptions::RESOURCE_BASED_CONSTRAINED_DELEGATION, value);
	return this;
}

bool PaPacOptions::getResourceBasedConstrainedDelegation() {
	return $nc(this->flags)->get(PaPacOptions::RESOURCE_BASED_CONSTRAINED_DELEGATION);
}

$bytes* PaPacOptions::asn1Encode() {
	$var($bytes, bytes, nullptr);
	{
		$var($DerOutputStream, temp, $new($DerOutputStream));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					int8_t var$1 = $DerValue::createTag($DerValue::TAG_CONTEXT, true, (int8_t)0);
					temp->write(var$1, $($nc(this->flags)->asn1Encode()));
					$assign(bytes, temp->toByteArray());
				} catch ($Throwable&) {
					$var($Throwable, t$, $catch());
					try {
						temp->close();
					} catch ($Throwable&) {
						$var($Throwable, x2, $catch());
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable&) {
				$assign(var$0, $catch());
			} /*finally*/ {
				temp->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	{
		$var($DerOutputStream, temp, $new($DerOutputStream));
		{
			$var($Throwable, var$2, nullptr);
			$var($bytes, var$4, nullptr);
			bool return$3 = false;
			try {
				try {
					temp->write($DerValue::tag_Sequence, bytes);
					$assign(var$4, temp->toByteArray());
					return$3 = true;
					goto $finally1;
				} catch ($Throwable&) {
					$var($Throwable, t$, $catch());
					try {
						temp->close();
					} catch ($Throwable&) {
						$var($Throwable, x2, $catch());
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable&) {
				$assign(var$2, $catch());
			} $finally1: {
				temp->close();
			}
			if (var$2 != nullptr) {
				$throw(var$2);
			}
			if (return$3) {
				return var$4;
			}
		}
	}
	$shouldNotReachHere();
}

$String* PaPacOptions::toString() {
	return $nc(this->flags)->toString();
}

PaPacOptions::PaPacOptions() {
}

$Class* PaPacOptions::load$($String* name, bool initialize) {
	$loadClass(PaPacOptions, name, initialize, &_PaPacOptions_ClassInfo_, allocate$PaPacOptions);
	return class$;
}

$Class* PaPacOptions::class$ = nullptr;

			} // internal
		} // krb5
	} // security
} // sun