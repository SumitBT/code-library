package swishtech.api.models;

import java.util.Date;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="user")
public class User
{
	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private long userId;
	
	@NotNull
	private String firstName;
	
	@NotNull
	private String lastName;
	
	@NotNull
	@Column(unique=true)
	private String email;
	
	@NotNull
	private String password;
	
	private String gender;
	
	private Date dob;
	
	private String occupation;
	
	@NotNull
	private long roleId;
	
	@NotNull
	private long statusId;
	
	@Column(columnDefinition = "DATETIME")
	@Temporal(TemporalType.TIMESTAMP)
	private Date signupDt;
	
	public User(){}
	
	public User(String firstName, String lastName, String email, String password, String occupation, String gender, Date dob)
	{
		this.firstName = firstName;
		this.lastName = lastName;
		this.email = email;
		this.password = password;
		this.occupation = occupation;
		this.gender = gender;
		this.dob = dob;
	}

	public long getUserId()
	{
		return userId;
	}

	public void setUserId(long userId)
	{
		this.userId = userId;
	}

	public String getFirstName()
	{
		return firstName;
	}

	public void setFirstName(String firstName)
	{
		this.firstName = firstName;
	}

	public String getLastName()
	{
		return lastName;
	}

	public void setLastName(String lastName)
	{
		this.lastName = lastName;
	}

	public String getEmail()
	{
		return email;
	}

	public void setEmail(String email)
	{
		this.email = email;
	}

	public String getPassword()
	{
		return password;
	}

	public void setPassword(String password)
	{
		this.password = password;
	}

	public String getOccupation()
	{
		return occupation;
	}

	public void setOccupation(String occupation)
	{
		this.occupation = occupation;
	}

	public long getRoleId()
	{
		return roleId;
	}

	public void setRoleId(long roleId)
	{
		this.roleId = roleId;
	}

	public long getStatusId()
	{
		return statusId;
	}

	public void setStatusId(long statusId)
	{
		this.statusId = statusId;
	}

	public Date getSignupDt()
	{
		return signupDt;
	}

	public void setSignupDt(Date signupDt)
	{
		this.signupDt = signupDt;
	}

	public String getGender()
	{
		return gender;
	}

	public void setGender(String gender)
	{
		this.gender = gender;
	}

	public Date getDob()
	{
		return dob;
	}

	public void setDob(Date dob)
	{
		this.dob = dob;
	}
	
}