package swishtech.sumitbt.models;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;

@Entity
@Table(name="passwordtokens")
public class PasswordResetToken
{
	
	@Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private long id;
    
	@NotNull
    private String token;
	
	@NotNull
	private long userId;
	
	@NotNull
	private boolean confirmed;
	
	public PasswordResetToken()
	{}

	public PasswordResetToken(String token, long userId)
	{
		this.token = token;
		this.userId = userId;
	}

	public Long getId()
	{
		return id;
	}

	public void setId(Long id)
	{
		this.id = id;
	}

	public String getToken()
	{
		return token;
	}

	public void setToken(String token)
	{
		this.token = token;
	}

	public boolean isConfirmed()
	{
		return confirmed;
	}

	public void setConfirmed(boolean confirmed)
	{
		this.confirmed = confirmed;
	}

	public long getUserId()
	{
		return userId;
	}

	public void setUserId(long userId)
	{
		this.userId = userId;
	}
	
}