package swishtech.api.models;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="account")
public class Account
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long accountId;
	
	@NotNull
	@Column(unique=true)
	private String email;
	
	@NotNull
	private String name;
	
	@NotNull
	private String website;
	
	@NotNull
	private String contactNo;
	
	@NotNull
	private String address;
	
	public Account(){}
	
	public Account(String name, String email,String website, String contactNo, String address)
	{
		this.email = email;
		this.name = name;
		this.website = website;
		this.contactNo = contactNo;
		this.address = address;
	}

	public long getAccountId()
	{
		return accountId;
	}

	public void setAccountId(long accountId)
	{
		this.accountId = accountId;
	}

	public String getName()
	{
		return name;
	}

	public void setName(String name)
	{
		this.name = name;
	}

	public String getEmail()
	{
		return email;
	}

	public void setEmail(String email)
	{
		this.email = email;
	}

	public String getWebsite()
	{
		return website;
	}

	public void setWebsite(String website)
	{
		this.website = website;
	}

	public String getContactNo()
	{
		return contactNo;
	}

	public void setContactNo(String contactNo)
	{
		this.contactNo = contactNo;
	}

	public String getAddress()
	{
		return address;
	}

	public void setAddress(String address)
	{
		this.address = address;
	}
	
}