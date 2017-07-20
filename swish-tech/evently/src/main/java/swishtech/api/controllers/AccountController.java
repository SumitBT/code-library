package swishtech.api.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import swishtech.api.models.Account;
import swishtech.api.models.User;
import swishtech.api.other.Response;
import swishtech.api.repositories.AccountRepo;
import swishtech.api.repositories.UserRepo;

@RestController
public class AccountController
{
	@Autowired
	private AccountRepo accountRepo;
	
	@Autowired
	private UserRepo userRepo;
	
	@ResponseBody
	@RequestMapping(value="/account",method=RequestMethod.GET)
	public Iterable<Account> show()
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			return accountRepo.findAll();
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/account",method=RequestMethod.POST)
	public Response add(@RequestBody Account account)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			Response response = new Response();
			try
			{
				if(account.getEmail().equals(null)||account.getEmail().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("Email can't be null!");
					return response;
				}
				else if(accountRepo.findByEmail(account.getEmail()) != null)
				{
					response.setSuccess(false);
					response.setMessage("Email already Exists!");
					return response;
				}
				else if(account.getName().equals(null)||account.getName().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("FirstName can't be null!");
					return response;
				}
				else if(account.getContactNo().equals(null)||account.getContactNo().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("LastName can't be null!");
					return response;
				}
				else if(account.getWebsite().equals(null)||account.getWebsite().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("Password can't be null!");
					return response;
				}
			}catch(Exception e)
			{
				response.setSuccess(false);
				response.setMessage(e.toString());
				return response;
			}
			accountRepo.save(account);
			return response;
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/account/{id}",method=RequestMethod.GET)
	public Account  details(@PathVariable long id)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			return accountRepo.findOne(id);
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/account/{id}",method=RequestMethod.PUT)
	public Response update(@PathVariable long id, @RequestBody Account account)
	{
		Response response = new Response();
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			Account a = accountRepo.findOne(id);
			if(a!=null)
			{
				try
				{
					if(account.getName().equals(null)||account.getName().equals(""))
					{
						response.setSuccess(false);
						response.setMessage("FirstName can't be null!");
						return response;
					}
					else if(account.getContactNo().equals(null)||account.getContactNo().equals(""))
					{
						response.setSuccess(false);
						response.setMessage("LastName can't be null!");
						return response;
					}
					else if(account.getWebsite().equals(null)||account.getWebsite().equals(""))
					{
						response.setSuccess(false);
						response.setMessage("Password can't be null!");
						return response;
					}
				}catch(Exception e)
				{
					response.setSuccess(false);
					response.setMessage(e.toString());
					return response;
				}
				a.setName(account.getName());
				a.setWebsite(account.getWebsite());
				a.setContactNo(account.getContactNo());
				accountRepo.save(a);
				return response;
			}
			else
			{
				response.setSuccess(false);
				response.setMessage("Invalid id");
				return response;
			}
		}
		else return null;
	}
}
